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
    int x = std::numeric_limits<int>::min();

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

// struct Node *temp{nullptr};
// void ReverseLinkedList_Recursion(struct Node *p)
// {
//     struct Node *tail{nullptr};
//     struct Node *tail_temp{nullptr};

//     while (p != nullptr)
//     {
//         tail = tail_temp;
//         tail_temp = p;
//         if (p->next == nullptr)
//             temp = p;

//         ReverseLinkedList_Recursion(p->next);
//         tail_temp->next = tail;
//     }
// }
int main()
{
    InsertAtPos(p, 0, 1);
    InsertAtPos(p, -1, 0);
    InsertAtPos(p, 1, 3);
    // InsertAtPos(p, 2, 4);
    // InsertAtPos(p, 3, 5);
    Display(p);

    // cout << DeleteNodeOfPos(p, 0) << endl;
    // cout << DeleteNodeOfPos(p, 10) << endl;
    // cout << DeleteNodeOfPos(p, 2) << endl;
    // cout << DeleteNodeOfPos(p, 1) << endl;

    // cout << isSorted(p) << endl;
    // removeDuplicateInSortedList(p);
    // Display(p);
    // p = ReverseLinkedList(p);
    // ReverseLinkedList_Recursion(p);
    // Display(temp);
}
