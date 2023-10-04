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

void ReverseLinkedList_Recursion(struct Node *start, Node *tail)
{
    if (start != nullptr)
    {
        ReverseLinkedList_Recursion(start->next, start);
        start->next = tail;
    }
    else
    {
        p = tail;
    }
}

Node *concatenate2lists(Node *first, Node *second)
{
    // very simple, just link the 1st list's last node to 2nd list's first node
    Node *start = first;
    while (first->next)
    {
        first = first->next;
    }
    first->next = second;
    return start;
}

Node *merging2sortedlists(Node *first, Node *second)
{
    // assuming lists are not empty and sorted

    // only once, for setting "start" and "temp" node
    struct Node *start, *temp;
    if (first->data < second->data)
    {
        start = temp = first;

        first = first->next;
        temp->next = nullptr;
    }
    else
    {
        start = temp = second;

        second = second->next;
        temp->next = nullptr;
    }

    while (first && second) // OR, while(first != nullptr && second != nullptr)
    {
        if (first->data < second->data)
        {
            temp->next = first;
            temp = first;
            first = first->next;
            temp->next = nullptr; // required?
        }
        else
        {
            temp->next = second;
            temp = second;
            second = second->next;
            temp->next = nullptr;
        }
    }

    // If there are remaining nodes in either list, append them to the merged list
    if (first == nullptr)
        temp->next = second;
    else
        temp->next = first;

    return start; // Return the head of the merged list
}

bool isHavingLoop(Node *slow)
{
    Node *fast{slow};

    while (slow && fast)
    {
        slow = slow->next;
        if (fast->next->next == nullptr)
        {
            return 0; // linear
        }
        else
        {
            fast = fast->next->next;
        }
        if (slow == fast)
        {
            return 1; // loop
        }
    }
    return 0; // linear(not having loop)
}

int main()
{
    Node *q;
    InsertAtPos(q, -2, 1);
    InsertAtPos(q, -3, 2);
    InsertAtPos(q, 9, 3);
    InsertAtPos(q, 10, 4);

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
    // ReverseLinkedList_Recursion(p, nullptr);
    // Display(p);

    // p = merging2sortedlists(p, q);
    // Display(p);

    cout << isHavingLoop(p);
}
