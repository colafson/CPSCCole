/*
 * Class: CPSC 122-02
 * Team Member 1: Cole Olafson
 * Team Member 2: N/A
 * Submitted by: Cole Olafson
 * GU username: colafson
 * file name: project1.cpp
 * This program illustrates generating prime numbers based on user input and can write the prime numbers to a file.
 * to build: g++ project1.cpp
 * to Execute: ./a.out filename
 * */

#include <iostream>
#include <fstream>
using namespace std;

bool is_prime(int);

int main(int argc, char* argv[])
{
	int x;
	int y;
	if(argc > 2)
	{
		cout << "ERROR" << endl;
		exit(-1);
	}
	cout << "How many prime numbers do you want: " <<endl;
	cin >> x;
	cout << "Over how many columns? " << endl;
	cin >> y;


        ofstream fout;
        fout.open(argv[1]);
        int v = 2;
        int q = 1;
        for(int i = x; i > 0; i--)
        {
                while(is_prime(v)==false)
                {
                        v++;
                }
                if(q == y)
                {
                fout << v << endl;
                q = 0;
                }
                else
                {
                        fout << v <<'\t';
                }
                v++;
                q++;
        }
        fout << endl;
        fout.close();

}

bool is_prime(int num)
{
	bool primeNums = true;
	for (int i=num-1; i>1; i--)
	{
		if(num % i == 0)
		{
			primeNums = false;
		}
	}

	return primeNums;

}
