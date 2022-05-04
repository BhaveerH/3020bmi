#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ounces2pounds(int x)
{
    return(x*16);
}

int stones2pounds(int x)
{
    return(x*14);
}

double weight2kg(int stones, int pounds, int ounces)
{
    return (stones2pounds(stones)+pounds+ounces2pounds(ounces))/2.2;
}

double height2metres(int feet, int inches)
{
    return(feet/3.82);
}

char categorise(double kg, double metre)
{
    double bmi = kg*kg/metre;
    char cat;
    if (bmi<19)
        cat='A';
    else if (bmi<=26)
        cat='B';
    else if (bmi<=300)
        cat='C';
    else
        cat='D';
    return(cat);
}

void process_data(char* input_file, char* output_file)
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string person_id;
    int pounds, stones, ounces, feet, inches;
    string spounds, sstones, sounces, sfeet, sinches;
    double kg, m;
    char cat;

    f_in.open(input_file,ios::in);
    f_out.open(output_file,ofstream::out);
    while (!f_in.eof())
    {
    	f_in >> person_id >> pounds >> stones >> ounces >> feet >> inches;
    	
    	spounds  = to_string(pounds);
        sstones  = to_string(stones);
        sounces  = to_string(ounces);
        sfeet  = to_string(feet);
        sinches  = to_string(inches);

        for (int i = 0; i < spounds.length(); i++)
        {

            if (isdigit(spounds[i]) == false)
            {

                cout << "Pounds input in not a number" << endl;
            }

        }


        for (int i = 0; i < sstones.length(); i++)
        {

            if (isdigit(sstones[i]) == false)
            {

                cout << "Stones input in not a number" << endl;
            }

        }


        for (int i = 0; i < sounces.length(); i++)
        {

            if (isdigit(sounces[i]) == false)
            {

                cout << "Ounces input in not a number" << endl;
            }

        }


        for (int i = 0; i < sfeet.length(); i++)
        {

            if (isdigit(sfeet[i]) == false)
            {

                cout << "Feet input in not a number" << endl;
            }

        }


        for (int i = 0; i < sinches.length(); i++)
        {

            if (isdigit(sinches[i]) == false)
            {

                cout << "Inches input in not a number" << endl;
            }

        }
        kg=weight2kg(int(stones),int(pounds),int(ounces));
        m =height2metres(int(feet),int(inches));
        cat=categorise(kg,m);
	f_out << person_id << " " << cat << endl;
    }
    f_in.close();
    f_out.close();
}
        
int main(int argc, char *argv[])
{
    process_data(argv[1], argv[2]);
}
