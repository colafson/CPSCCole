/*
 * Class: CPSC 122-02
 * Cole Olafson
 * GU Username: colafson
 * Submitted by Cole Olafson
 * file name: project2.cpp
 * Program illustrates file and character manipulation and composition by using a cipher
 * To Build: g++ project2.cpp
 * To Execute: ./a.out inputFile ouputFile action shift
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

char transform(char ch, int action, int shift);
void gfopen(char[],ifstream&);

int main(int argc, char* argv[])
{

	string ch;
	ifstream fin;
	ofstream fout;
	int action = atoi(argv[3]);
	int shift = atoi(argv[4]);
	fout.open(argv[2]);
	gfopen(argv[1],fin);

	while(fin.peek() != EOF)
 	{
		fout << transform(fin.get(), action, shift);
	}
	cout << endl;
	fin.close();

}


void gfopen(char fileName[], ifstream& fin)
{
	fin.open(fileName);

	if(!fin)
	{
		cout << "Error opening input file" << endl;
		exit(EXIT_FAILURE);
	}
}
/*
Pre: 	ch is the character to be encoded.
	action is 0/1, 0 means encrypt, 1 means decrypt
 	shift is an integer in the range [1..25]
Post:  returns an encrypted/decrypted character
*/

char transform(char ch, int action, int shift)
{
	if(isalpha(ch) == false)
	{
		return ch;
	}
	ch = toupper(ch);
	ch -= 65;
	if(action == 0)
	{
		ch = (ch + shift)%26;
	}
	if(action == 1)
	{
		ch =((ch - shift)+26) % 26;
	}
	ch += 65;
	return ch;
}
