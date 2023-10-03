#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *p = nullptr; // global pointer instance of type Struct Node

struct Node *createNode(int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    return newNode;
}
void createFromArray(vector<int> A)
{
    struct Node *last{nullptr};
    p = createNode(A[0]);
    last = p;

    for (int i = 1; i < A.size(); i++)
    {
        last->next = createNode(A[i]);
        last = last->next;
    }
}

void Display_Loop(struct Node *p) //&p(ref to p) will change the original global variable
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void Display_Recursion(struct Node *p)
{
    if (p != nullptr)
    {
        cout << p->data << " ";
        Display_Recursion(p->next);
    }
}

void DisplayReverse_Recursion(struct Node *p)
{
    if (p != nullptr)
    {
        DisplayReverse_Recursion(p->next);
        cout << p->data << " ";
    }
}

int CountNodes_Recursion(struct Node *p)
{
    if (p == nullptr)
        return 0;

    return CountNodes_Recursion(p->next) + 1;
}

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

// sum of all elements in linked list
int Add_Recursion(struct Node *p) // assuming all data is of type int
{
    if (p->next == nullptr)
    {
        return p->data;
    }
    return Add_Recursion(p->next) + p->data;
}

Node *linearSearchAndMoveToFront(struct Node *p, int elem)
{
    // if first node has element, then return original list
    if (p->data == elem)
    {
        return p;
    }

    struct Node *start = p;
    struct Node *prev = p;
    p = p->next;

    while (p != nullptr)
    {
        if (p->data == elem)
        {
            prev->next = p->next;
            p->next = start;
            start = p;
            return start;
        }

        // increment(move) both prev and p
        prev = p;
        p = p->next;
    }

    // if not found
    return start; // original list
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
void InsertAtSortedList(Node *&p, int value)
{
    Node *start = p;

    Node *newNode = new Node{
        data :
            value,
        next : nullptr
    };

    // if new element is the smallest
    if (value < (start->data))
    {
        newNode->next = p;
        p = newNode;
    }

    else
    {
        // keeping a tail pointer
        Node *prev = nullptr;
        while (start != nullptr && start->data < value)
        {
            prev = start;
            start = start->next;
        }
        newNode->next = start;
        prev->next = newNode;
    }
}
// will return the deleted node's data, else will return -1
int DeleteNodeOfPos(Node *&p, int pos)
{
    // index 0 and below is not allowed
    if (pos <= 0)
    {
        cout << "Deletion of index 0 and below is not allowed \t";
        return -1;
    }

    if (pos > CountNodes(p))
    {
        cout << "Cannot delete at pos " << pos << ", It is out of the limit(No item present) Total nodes present is/are:" << CountNodes(p) << "\t";

        return -1;
    }
    Node *start{p};
    Node *prev{nullptr};
    int x;

    if (pos == 1)
    {
        p = p->next;
        x = start->data;
        start->next = nullptr; // is this step required?
        delete start;
        cout << "Node deleted with data value: ";
        return x;
    }

    for (int i = 1; i < pos; i++)
    { // for pos 2+
        prev = start;
        start = start->next;
    }
    prev->next = start->next;
    x = start->data;
    delete start; // should i do start->next = nullptr first? to avoid mem leak
    cout << "Node deleted with data value: ";
    return x;
}

bool isSorted(Node *p)
{
    int x = std::numeric_limits<int>::min(); // comparing with the smallest int value

    // if list is empty print msg
    if (p == nullptr)
    {
        cout << "list is empty ";
        return 0;
    }
    while (p != nullptr)
    {
        if (x > p->data)
        {
            cout << "not sorted ";
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    cout << "sorted ";
    return 1;
}

// remove duplicates in the sorted list (if found)
void removeDuplicateInSortedList(Node *&p)
{
    // assuming the list is sorted, and not empty

    Node *q = p->next;
    Node *start = p;

    while (q != nullptr)
    {
        if (q->data == start->data)
        {
            start->next = q->next;
            delete q;
            q = start->next;
        }
        else
        {
            start = q;
            q = q->next;
        }
    }
}

//changing the links(not the elements)
struct Node *ReverseLinkedList(struct Node *p)
{
    // r <- q <- p (changing q, while keeping a ref to r and p i.e, prev and next node)
    Node *r{nullptr};
    Node *q{nullptr};

    while (p != nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}
int main()
{
    struct Node *z{nullptr}; // stored in stack
    vector<int> A = {1, 2, 3, 4, 5, 6};
    // p->data = 20; //exception error, beacuse global p is pointing to nullptr
    // p->next = nullptr;
    createFromArray(A);
    Display_Loop(p);
    Display_Recursion(p);
    cout << endl;
    DisplayReverse_Recursion(p);
    cout << endl;
    cout << "Total Nodes(using recursion): " << CountNodes_Recursion(p) << endl;
    cout << "Total Nodes(using loop): " << CountNodes(p) << endl;
    cout << "Sum of all elements: " << Add_Recursion(p) << endl;
    cout << endl;

    p = linearSearchAndMoveToFront(p, 5);
    Display_Loop(p);
    p = linearSearchAndMoveToFront(p, 6);
    Display_Loop(p);

    // inserting when list was NOT empty
    InsertAtPos(p, 999, 2);
    InsertAtPos(p, 800, 8);
    InsertAtPos(p, 400, 10); // outside the limit
    Display_Loop(p);

    // inserting when list was empty
    InsertAtPos(z, 0, 1);
    InsertAtPos(z, -1, 0);
    InsertAtPos(z, 7, -1);
    InsertAtPos(z, 2, 3);
    InsertAtPos(z, 5, 4);
    Display_Loop(z);

    InsertAtSortedList(z, 4);
    InsertAtSortedList(z, -2);
    InsertAtSortedList(z, 6);
    InsertAtSortedList(z, 6);
    cout << endl;

    cout << DeleteNodeOfPos(z, 0) << endl;
    cout << DeleteNodeOfPos(z, 10) << endl;
    cout << DeleteNodeOfPos(z, 2) << endl;
    cout << DeleteNodeOfPos(z, 1) << endl;
    Display_Loop(z);

    cout << isSorted(p) << endl;
    cout << isSorted(z) << endl;
    cout << endl;

    removeDuplicateInSortedList(z);
    Display_Loop(z);

    z = ReverseLinkedList(z);
    Display_Loop(z);
}
