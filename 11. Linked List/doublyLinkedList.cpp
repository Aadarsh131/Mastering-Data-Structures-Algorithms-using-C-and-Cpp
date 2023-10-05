#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = nullptr;

Node *createDoublyLLfromArray(int A[], int size)
{
    struct Node *start = new Node{prev : nullptr, data : A[0], next : nullptr};
    first = start;

    for (int i = 1; i < size; i++)
    {
        Node *last = new Node{prev : nullptr, data : A[i], next : nullptr};

        start->next = last;
        last->prev = start;

        last = last->next;
        start = start->next;
    }
    return first;
}

void DisplayDLL(Node *start)
{
    while (start != nullptr)
    {
        cout << start->data << " ";
        start = start->next;
    }
    cout << endl;
}

int LengthOfDLL(Node *start)
{
    int len = 0;
    while (start != nullptr)
    {
        len++;
        start = start->next;
    }
    return len;
}

void InsertAtPositionDLL(Node *&start, int pos, int value)
{
    struct Node *newNode = new Node{prev : nullptr, data : value, next : nullptr};

    if (pos <= 0)
    {
        cout << "Invalid position, pos should be greater than 0 " << endl;
        return;
    }
    if (pos == 1)
    {
        // if list is empty
        if (start == nullptr)
        {
            start = newNode;
        }
        else
        {
            newNode->next = start;
            start->prev = newNode;
            start = newNode;
        }
    }
    else
    {
        struct Node *temp{start};
        for (int i = 0; i < pos - 2; i++) // move 1 node before the pos
        {
            if (temp->next == nullptr)
            {
                cout << "Invalid Pos" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        if (temp->next == nullptr)
            temp->next = newNode;
        else
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        // delete temp;

        // is this code mem safe?
    }
}

void DeleteFromPosDLL(Node *&start, int pos)
{
    if (pos <= 0)
    {
        cout << "Invalid Pos, Pos should be greater than 0 " << endl;
        return;
    }
    if (pos == 1)
    {
        start = start->next;
        start->prev = nullptr;
        // mem leak
    }
    else
    {
        Node *q{start};
        Node *temp{nullptr};              // to be deleted
        for (int i = 0; i < pos - 2; i++) // move 1 node before the node to be deleted
        {
            q = q->next;
            if (q->next == nullptr)
            {
                cout << "Invalid Position, cannot delete" << endl;
                return;
            }
        }
        temp = q->next;
        if (temp->next) // if not the last node
        {
            q->next = temp->next;
            temp->next->prev = q;

            temp->prev = nullptr;
            temp->next = nullptr;
        }
        else // last node
        {
            q->next = nullptr;
            temp->prev = nullptr;
            delete temp;
        }

        // delete temp;
    }
}

int main()
{
    int A[] = {5, 6, 7, 2, 6, 8, 3, 2, 4, 1};
    int sizeOfArray = sizeof(A) / sizeof(A[0]);

    first = createDoublyLLfromArray(A, sizeOfArray);
    DisplayDLL(first);

    cout << "length of DLL: " << LengthOfDLL(first) << endl;

    InsertAtPositionDLL(first, 11, 99);
    DisplayDLL(first);

    DeleteFromPosDLL(first, 10);
    DisplayDLL(first);
}