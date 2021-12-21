#include <iostream>
using namespace std;
class Node
{
public:
    double data;
    Node *Next;
};
class List
{
private:
    Node *head;

public:
    List() { head = NULL; } //default constructor
    bool IsEmpty() { return head == NULL; }
    bool InsertNode(int index, double x);
    int FindNode(double x);
    int DeleteNode(double x);
    void DisplayList(void); //function used to show the size of the list
    ~List();
};

bool List::InsertNode(int index, double x)
{
    if (index < 0)
        return false;
    if (index > 0 && head == NULL)
        return false;
    Node *newNode;
    newNode = new Node;
    newNode->data = x;
    if (index == 0)
    {
        newNode->Next = head;
        head = newNode;
        return true;
    }
    if (index >= 1)
    {
        int currIndex = 0;
        Node *currNode;
        currNode = head;
        while (currNode->Next != NULL && currIndex < index)
        {
            currNode = currNode->Next;
            currIndex++;
        }
        newNode->Next = currNode->Next;
        currNode->Next = newNode;
        return true;
    }
}

int List::FindNode(double x)
{
    Node *currNode = head;
    int currIndex = 0;
    while (currNode->Next != NULL && currNode->data != x)
    {
        currNode = currNode->Next;
        currIndex++;
    }
    if (currNode != NULL)
        return currIndex;
    return -1;
}
void List::DisplayList()
{
    int num = 0;
    Node *currNode = head;
    while (currNode != NULL)
    {
        cout << currNode->data << endl;
        currNode = currNode->Next;
        num++;
    }
    cout << "Number of nodes in the list: " << num << endl;
}
int List::DeleteNode(double x)
{
    Node *prevNode = NULL;
    Node *currNode = head;
    int currIndex = 0;
    while (currNode != NULL && currNode->data != x)
    {
        prevNode = currNode;
        currNode = currNode->Next;
        currIndex++;
    }
    if (currNode)
    {
        if (prevNode)
        {
            prevNode->Next = currNode->Next;
            delete currNode;
        }
        else
        {
            head = currNode->Next;
            delete currNode;
        }
        return currIndex;
    }
    return -1;
}
