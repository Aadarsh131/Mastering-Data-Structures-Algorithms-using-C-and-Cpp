#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *p;   // stored in stack
    struct Node *pos; // for traversing
    p = new Node;
    pos = p;

    p->data = 10;
    p->next = nullptr;

    while (pos != nullptr)
    {
        cout << pos->data << " ";
        pos = pos->next;
    }
}
