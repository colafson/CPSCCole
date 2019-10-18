/*
Class: CPSC 122-02
Cole Olafson
GU Username: colafson
Submitted By: Cole Olafson
File Name: project 5
This project illustrates file manipulation and dynamically allocated memory
To Build: g++ project5.cpp project5Tst.cpp
To Execute: ./a.out
*/

#include <iostream>
using namespace std;

#include "project5.h"
/*
Pre:  strIn is a null-terminated array of characters
Post: An instance of Mystring is created and set to the contents of strIn
*/
//Constructor function
MyString::MyString(char const* strIn)
{
 cout << "constructor" << endl;
 //determine the length of MyString instance
 length = 0;
 while(strIn[length] != '\0')
  length++;

 //dynamically allocate memory for MyString instance
 str = new char[length + 1];

 //copy contents of strIn to MyString instance
 int i = 0;
 while(i < length)
 {
  str[i] = strIn[i];
  i++;
 }
 str[i] = '\0';
}
/*
   Pre:  An instance of MyString exists 
   Post: Invoked automatically when a static instance of MyString 
         goes out of scope. Invoked when a dynamic instance of MyString
         is deleted.  
   */
//Destructor function
MyString::~MyString()
{
 delete [] str;
 cout << "destructor" << endl;
}
   /*
   Pre:  An instance of MyString exists
   Post: Contents of the instance of myString is displayed on the screen
   */

void MyString::myDisplay()
{
 for (int i = 0; i < length; i++)
  cout << str[i];
 cout << endl;
}
   /*
   Pre:  An instance of MyString exists whose length <= length of strIn
   Post: The contents of strIn overwrites the contents of the instance
         of MyString pointed to by the member variable str.  str is
         terminated by the null character.
   */

void MyString::myStrcpy(char const* strIn)
{
 cout << "copy" << endl;
 int strInLen = 0;
 while(strIn[strInLen] != '\0')
  strInLen++;

 char* temp = new char[strInLen + 1];
 int i = 0;
 while(i < strInLen)
 {
  temp[i] = strIn[i];
  i++;
 }
 delete [] str;
 str = temp;
 temp = NULL;
 length = strInLen;
}

   /*
   Pre:  An instance of MyString exists
   Post: Returns the number of characters, excluding the null character
         in MyString. 
   */

int MyString::myStrlen()
{
 return length;
}
   /*
   Pre:  An instance of MyString exists. strIn is a null-terminated
         string.
   Post: Returns true if the strings are equivalent, false otherwise 
   */

bool MyString::isEqual(char const* strIn)
{
 int strInLen = 0;
 int i = 0;
 while(strIn[i] != '\0')
 {
  strInLen++;
  i++;
 }
 if(strInLen != length)
  return false;
 for(int j = 0; j<length; j++)
 {
  if(strIn[i] != str[i])
   return false;
 }
 return true;
}
   /*
   Pre:  An instance of MyString exists
   Post: If strIn is a substring of the instance of MyString, returns
         the index of its starting positon, -1 otherwise
   */

int MyString::find(char const* strIn)
{
 int strInLen = 0;
 while(strIn[strInLen] != '\0')
  strInLen++;
 int startIdx = -1;
 int i = 0;
 while(startIdx == -1 && i < length)
 {
  if(str[i] == strIn[0])
   startIdx =i;
  i++;
 }
 int j = startIdx;
 i = 0;
 if(startIdx != -1)
 {
  while(j < (startIdx + strInLen))
  {
   if(str[j] != str[i])
    return -1;
   i++;
   j++;
  }
 }
 return startIdx;
}
   /*
   Pre:  An instance of MyString exists. strIn is a null-terminated string
   Post: strIn is concatenated with the instance of MyString.  Ex.
         MyString is ABC. strIn is DEF.  MyString is still a null-terminated
         string, but contains: ABCDEF. 
   */

void MyString::concat(char const* strIn)
{
 int strInLen = 0;
 while(strIn[strInLen] != '\0')
  strInLen++;
 char* temp = new char[length + strInLen + 1];
 int i = 0;
 while(i < length)
 {
  temp[i] = str[i];
  i++;
 }
 temp[i] = '\0';

 delete [] str;
 str = temp;
 temp = NULL;
 length += strInLen;
}



