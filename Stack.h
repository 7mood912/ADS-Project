#include <iostream>
using namespace std;
class node
{
public:
    double data;
    node *Next;
};
class Stack
{
    node *head;
    int size;
    int capacity;

public:
    Stack()
    {
        head = NULL;
        size = 0;
        capacity = 100;
    }
    void Push(double element)
    {
        if (size == capacity)
            cout << "stack is full";
        else
        {
            node *newNode = new node;
            newNode->data = element;
            newNode->Next = head;
            head = newNode;
            size++;
        }
    }
    void Pop()
    {
        if (head == NULL)
            cout << "nothing to pop";
        else
        {
            head = head->Next;
            size--;
        }
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << ",";
            temp = temp->Next;
        }
        cout << endl;
    }
};
