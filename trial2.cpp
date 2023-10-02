#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *p = nullptr;
int CountNodes(struct Node *p)
{
    int count = 0;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    return count;
}
void InsertAtPos(struct Node *&p, int value, int pos) // modifying the original list
{
    struct Node *temp = p;
    struct Node *newNode = new Node{data : value, next : nullptr};

    if (p == nullptr) // when list is empty
    {
        if (pos == 1)
            p = newNode;
        else
            cout << "On the first Insert, you can only insert at position 1 " << endl;
    }
    else if (pos == 0)
    {
        newNode->next = temp;
        p = newNode;
    }
    else
    {
        int listSize = CountNodes(p);
        if (pos >= 1 && pos <= listSize + 1)
        {

            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "Couldn't insert " << value << " at position " << pos << ", it is outside the limit of (listSize + 1)" << endl;
        }
    }
}

void Display(Node *p)
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    InsertAtPos(p, 0, 1);
    InsertAtPos(p, -1, 0);
    InsertAtPos(p, 7, -1);
    InsertAtPos(p, 2, 3);
    InsertAtPos(p, 3, 4);

    Display(p);
}