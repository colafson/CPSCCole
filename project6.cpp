#include <iostream>
using namespace std;

#include "project6.h"

List::List()
{
 head = NULL;
 length = 0;
}

List::~List()
{
 while(length > 0)
  DeleteItemH();
}

bool List::IsEmpty() const
{
 return (length == 0);
}


int List::GetLength() const
{
 return length;
}

void List::PutItemH(const itemType newItem)
{
 node* temp = new node;
 temp->item = newItem;
 temp->next = head;
 head = temp;
 length++;
}

itemType List::GetItemH() const
{
 return head->item; 
}

void List::DeleteItemH()
{
 node* temp = head->next;
 delete head;
 head = temp;
 temp = NULL;
 length--;
}
	
void List::Print() const
{
 node* temp = head;
 while(temp != NULL)
 {
  cout << temp->item << endl;
  temp = temp->next;
 }
}

int List::Find(const itemType item) const
{
 int idx = -1;
 int i = 0;
 node* temp = head;
 while(idx == -1 && temp != NULL)
 {
  if(temp->item == item)
   idx = i;
  i++;
  temp = temp->next;
 }
 return idx;
}

void List::DeleteItem(const int pos)
{
 int i = 0;
 node* prev = head;
 node* cur = head; 
 while(i < pos)
 {
  prev = cur;
  cur = cur->next;
  i++;
 }
 prev->next = cur->next;
 delete cur;
 length--;
 prev = cur = NULL;
}
