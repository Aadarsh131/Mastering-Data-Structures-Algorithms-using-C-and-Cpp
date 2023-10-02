## Self referential structure
```cpp
struct Node{
    int data;
    struct Node *next; //a DS as a type in its implementation (self referential structure)
}
```

## Basic creation of linked list
```cpp
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

void Display_Loop(struct Node *p) //&p(ref to p) will change the original global variable, OR double pointer can also be used(strct Node **p) to manipulate the original node
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

int main()
{
    // struct Node *p{nullptr};   // stored in stack
    vector<int> A = {1, 2, 3, 4, 5, 6};
    createFromArray(A);
    Display_Loop(p);
    Display_Recursion(p);
    cout << endl;
    DisplayReverse_Recursion(p);
    cout << endl;
    cout << "Total Nodes(using recursion): " << CountNodes_Recursion(p) << endl;
    cout << "Total Nodes(using loop): " << CountNodes(p) << endl;
    cout << "Sum of all elements: " << Add_Recursion(p) << endl;
}

```

## Linear Search *(and moving that element to front/head)*
```cpp
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
```
```cpp
p = linearSearchAndMoveToFront(p, 5);
Display_Loop(p); //5 1 2 3 4 6 

p = linearSearchAndMoveToFront(p, 6);
Display_Loop(p); //6 5 1 2 3 4 
```

## Insert Node at specified position *(only when list is already present)*
```cpp
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
```
```cpp
InsertAtPos(p, 999, 2); // 1 999 2 3 4 5 6
InsertAtPos(p, 800, 8); // 1 999 2 3 4 5 6 800
InsertAtPos(p, 400, 10); // outside the limit

Display_Loop(p); 
//Output:
// cannot insert outside the limit of (listSize + 1)
//1 999 2 3 4 5 6 800 
```

## Insert At Sorted List
```cpp
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
```
```cpp
//Before: -1 0 2 5
InsertAtSortedList(z, 4);
Display_Loop(z); //-1 0 2 4 5


InsertAtSortedList(z, -2);
Display_Loop(z); //-2 -1 0 2 4 5

```