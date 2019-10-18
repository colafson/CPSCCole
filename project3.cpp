/*
 * Class: CPSC 122-02
 * Cole Olafson
 * GU Username: colafson
 * Submitted by Cole Olafson
 * file name: project3.cpp
 * Program illustrates file and character manipulation and composition by using a cipher
 * To Build: g++ project3.cpp
 * To Execute: ./a.out inputFile ouputFile inverseFile action shift1 shift2
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

char transform(char ch, int action, int shift1, int shift2, int arr[]);
void fileOpen(char[], char, fstream&);
int getInverse(int shift1, int arr[]);

int main(int argc, char* argv[])
{

	fstream output;
	fstream input;
	fstream inverses;
	int action = atoi(argv[4]);
	int shift1 = atoi(argv[5]);
	int shift2 = atoi(argv[6]);

	fileOpen(argv[1],'r',input);
	fileOpen(argv[2],'w',output);
	fileOpen(argv[3],'r',inverses);

	int arr[26];
	int num;
        int i = 0;
        while(inverses >> num)
	{
		arr[i] = num;
		i++;
	}
	while(input.peek() != EOF)
 	{
		output.put(transform(input.get(), action, shift1, shift2, arr));
	}
	cout << endl;
	input.close();
	return 0;
}

char transform(char ch, int action, int shift1, int shift2, int arr[])
{
	if(isalpha(ch) == false)
	{
		return ch;
	}
	ch = toupper(ch);
	ch -= 65;
	if(action == 0)
	{
		ch = ((ch * shift1) + shift2)%26;
	}
	if(action == 1)
	{
		shift1 = getInverse(shift1,arr);
		ch =(((ch*shift1) -shift1* shift2)+676) % 26;

	}
	ch += 65 ;
	return ch;
}

int getInverse(int shift1, int arr[])
{
	return arr[shift1];
}

void fileOpen(char name[], char mode,fstream& file)
{
	string fileType;

	if (mode == 'r')
		fileType = "input";
	if (mode == 'w')
		fileType = "output";

	if (mode == 'r')
		file.open(name, ios::in);
	if (mode == 'w')
		file.open(name, ios::out);

	if (file.fail())
	{
		cout << "Error opening " << fileType << " file" << endl;
		exit(EXIT_FAILURE);
	}
}
