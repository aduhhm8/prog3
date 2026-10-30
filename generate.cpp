// Author: Adam Cobian
// CECS 325-01
// Prog 3
// Due: 10/12/26
//
//I certify that this program is my own original work. I did not copy any part of
//this program from any other source including inappropriate AI use. I did not share 
//this program with anyone. I further certify that I typed each and every line of code 
//in this program.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int loki;
int main(int argc, char *argv[])
	    
{
    cout << "argc = " << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }

    if (argc != 4) 
    {
        cout << "Error - wrong number of arguments" << endl;
        cout << "Usage: generate COUNT MIN MAX" << endl;
        return 1;
    }

    int count = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    srand(time(0));
    ofstream fout;
    fout.open("numbers.dat");

    if (!fout)
    {
        cout << "Error - could not open numbers.dat" << endl;
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        int num = rand() % (max - min + 1) + min;
        fout << num << endl;
    }

    fout.close();
    cout << "Created numbers.dat with " << count << " numbers" << endl;

    return 0;
}
