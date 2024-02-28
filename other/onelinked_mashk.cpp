#include <iostream>
#include <fstream>
#include <math.h>

#define NMAX 10

using namespace std;

struct Node
{
   int key;    // информационное поле
   Node *next; // адресное поле
};

void push(Node *&head, int key)
{
   Node *new_node = new Node();
   new_node->key = key;
   new_node->next = head;
   head = new_node;
}

void pushBack(Node *&head, int key)
{
   if (head == NULL)
      push(head, key);
   else
   {
      Node *n = head;
      Node *tail;
      for (n; n; n = n->next)
      {
         tail = n;
      }
      Node *temp = new Node();
      temp->key = key;
      temp->next = NULL;
      tail->next = temp;
   }
}

int main()
{
   int i, x = 1000;
   Node *head = NULL;
   Node *n = head;
   push(head, 10);
   push(head, 20);
   pushBack(head, 30);
   for (head; head; head = head->next)
   {
      cout << head->key << endl;
   }
}