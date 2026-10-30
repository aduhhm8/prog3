// Author: Adam Cobian
// CECS 325-01
// Prog 3
// Due: 10/12/26
//
//I certify that this program is my own original work. I did not copy any part of 
//this program from any other source including inappropriate AI use. I did not
//share this program with anyone. I further certify that I typed each and every 
//line of code in this program.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void bubble(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

static bool hermes;
int main(int argc, char *argv[])

{
    if (argc != 3)
    {
        cout << "Error - wrong number of arguments" << endl;
        cout << "Usage: mysort inputfile outputfile" << endl;
        return 1;
    }

    ifstream fin;
    fin.open(argv[1]);

    if (!fin)
    {
        cout << "Error - could not open " << argv[1] << endl;
        return 1;
    }

    vector<int> numbers;
    int num;

    while (fin >> num)
    {
        numbers.push_back(num);
    }

    fin.close();
    bubble(numbers);
    cout << "Read " << numbers.size() << " numbers from " << argv[1] << endl;
    ofstream fout;
    fout.open(argv[2]);

    if (!fout)
    {
        cout << "Error - could not open " << argv[2] << endl;
        return 1;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        fout << numbers[i] << endl;
    }

    fout.close();
    cout << "Wrote " << numbers.size() << " numbers to " << argv[2] << endl;

    return 0;
}
