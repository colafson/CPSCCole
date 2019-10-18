/*
Class: CPSC 122-01
Cole Olafson
GU Username: colafson
Submitted By: Cole Olafson
File Name: project 4
This project illustrates file manipulation and dynamically allocated memory
To Build: g++ inClassEx2Start.cpp
To Execute: ./a.out input output size_of_file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void fileOpen(fstream&, char[], char);
void readData(fstream&, char[], string[], int);
void writeData(fstream&, char[], string[], int);
void selSort(string[], int);
int findSmallest(string[], int, int);
void swap(string[], int, int);

int main(int argc, char* argv[]) {
	fstream fin;
	fstream fout;
	string line;


	if (argc != 4)
	{
		cout << "Incorrect number of command line arguments" << endl;
		exit(EXIT_FAILURE);
	}

	int SIZE = atoi(argv[3]);

	string * data = new string[SIZE];

	readData(fin, argv[1], data, SIZE);

	selSort(data, SIZE);

	writeData(fout, argv[2], data, SIZE);

	return 0;
}

void readData(fstream& file, char fileName[], string data[], int SIZE) {
	fileOpen(file, fileName, 'r');
	for (int i = 0; i < SIZE; i++)
		getline(file,data[i]);
	file.close();
}

void writeData(fstream& file, char fileName[], string data[], int SIZE) {
	fileOpen(file, fileName, 'w');
	for (int i = 0; i < SIZE; i++)
		file << data[i] << endl;
	file.close();
}

void fileOpen(fstream& file, char name[], char mode) {
	string fileType;

	if (mode == 'r')
		fileType = "input";
	if (mode == 'w')
		fileType = "output";

	if (mode == 'r')
		file.open(name, ios::in);  //available thorugh fstream
	if (mode == 'w')
		file.open(name, ios::out);  //available through fstream;

	if (file.fail()) { //error condition
		cout << "Error opening " << fileType << " file" << endl;
		exit(EXIT_FAILURE);
	}
}

/*
Pre:  data is an array of strings
Post: data is in sorted order
*/
void selSort(string data[], int SIZE) {
	int cur;
	int smallI;
	for(int cur = 0; cur < SIZE - 1; cur++) {
		smallI = findSmallest(data, cur, SIZE);
		swap(data, cur, smallI);
	}
}

/*
Pre:  data is an arrray of strings, cur begins the subarray under consideration
Post: returns the smallest item in the array, beginnig with cur
*/
int findSmallest(string data[], int cur, int SIZE) {
	int smallestI = cur;
	for(int i = cur; i < SIZE; i++)
		if(data[i] < data[smallestI])
			smallestI = i;
	return smallestI;
}


/*
Pre:  data is an arrray of strings, cur and idxSmallest are indices
Post: what was in postion cur is now in position idxSmallest and vice-versa
*/
void swap(string data[], int cur, int idxSmallest) {
	string temp = data[cur];
	data[cur] = data[idxSmallest];
	data[idxSmallest] = temp;
}
