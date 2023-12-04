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
    Node *start{p}; // NOTE: Node* &start{p}; would create a reference instead of a copy of p, and hence a change of value in `start` would change a value in `p` and viceversa. In our case it would also create a data race becuase we are deleting `start`

    Node *prev{nullptr};
    int x;

    cout << start << "," << p << endl;
    p = p->next;
    cout << start << "," << p << endl;

    // if (pos == 1)
    // {
    //     p = p->next;
    //     x = start->data;
    //     start->next = nullptr; // is this step required?
    //     delete start;
    //     cout << "Node deleted with data value: ";
    //     return x;
    // }

    // for (int i = 1; i < pos; i++)
    // { // for pos 2+
    //     prev = start;
    //     start = start->next;
    // }
    // prev->next = start->next;
    // x = start->data;
    // delete start; // should i do start->next = nullptr first? to avoid mem leak
    // cout << "Node deleted with data value: ";
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

// changing the links(not the elements)
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
        if (fast->next == nullptr || fast->next->next == nullptr)
        {
            cout << "Not having loop(linear list) \t";
            return 0; // linear
        }
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Having loop \t";
            return 1; // loop
        }
    }
}

// created by chatgpt
//  Function to insert a node at the end of the circular linked list
void CircularLLInsertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node{data : val, next : nullptr};

    if (head == nullptr)
    {
        // If the list is empty, make the new node the head and point it to itself
        head = newNode;
        head->next = head;
    }
    else
    {
        // Find the last node and update its 'next' pointer to point to the new node
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Make the new node point to the head to complete the loop
    }
}

void CircularLLInsertAtPos(Node *&head, int pos, int value)
{
    Node *temp{head};
    Node *newNode = new Node{data : value, next : nullptr};
    if (pos <= 0)
    {
        cout << "Invalid pos, pos should be greater than 0 " << endl;
        return;
    }
    if (pos == 1)
    {
        // if list is empty, insert a new Node for pos=1
        if (head == nullptr)
        {

            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            // when list is not empty
            // traverse till we reach 1 pos before the head node
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode; // update the head to the new node
        }
    }
    else // any pos > 1
    {
        // 2 methods as of what I can think
        // Method 1- traverse for pos-2,  if found p->next==head, then return and print msg of Invalid position (TimeComplexity is less)

        // Method 2- count all the nodes first, if pos > (1+totalNodes) then, output msg of Invalid position
        // (Time complexity is O(n) as for counting we have to traverse all the nodes )

        // method 1-
        for (int i = 1; i <= pos - 2; i++)
        {
            if (temp->next == head)
            {
                cout << "Invalid position " << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void DeleteFromCircularLL(Node *&head, int pos)
{
    Node *prev{head};
    Node *temp{nullptr}; // node to be deleted

    if (pos == 0)
    {
        cout << "Invalid pos, pos should be greater than 0" << endl;
        return;
    }
    if (pos == 1)
    {
        while (prev->next != head)
        {
            prev = prev->next;
        }
        prev->next = head->next;
        head = head->next;
    }
    else
    {
        for (int i = 1; i <= pos - 2; i++)
        {
            prev = prev->next;
            if (prev->next == head)
            {
                cout << "Invalid Position" << endl;
                return;
            }
        }
        temp = prev->next;
        prev->next = temp->next;
        temp->next = nullptr;
        delete temp;
    }
}

void DisplayCircularLL(Node *p)
{
    Node *head{p};

    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

void DisplayCircularLL_Recursion(Node *current, Node *head)
{
    if (current->next != head)
    {
        cout << current->data << " ";
        DisplayCircularLL_Recursion(current->next, head);
    }
    else
        cout << current->data;
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

    // cout << DeleteNodeOfPos(z, 0) << endl;
    // cout << DeleteNodeOfPos(z, 10) << endl;
    // cout << DeleteNodeOfPos(z, 2) << endl;
    cout << DeleteNodeOfPos(z, 1) << endl;
    Display_Loop(z);

    // cout << isSorted(p) << endl;
    // cout << isSorted(z) << endl;
    // cout << endl;

    // removeDuplicateInSortedList(z);
    // Display_Loop(z);

    // // z = ReverseLinkedList(z);
    // // Display_Loop(z);

    // ReverseLinkedList_Recursion(p, nullptr);
    // Display_Loop(p);

    // // p = concatenate2lists(p, z);
    // // Display_Loop(p);
    // cout << endl;

    // struct Node *q{nullptr};
    // InsertAtPos(q, -2, 1);
    // InsertAtPos(q, -3, 2);
    // InsertAtPos(q, 9, 3);
    // InsertAtPos(q, 10, 4);

    // q = merging2sortedlists(q, z); // assuming q and z are sorted list
    // cout << "After merging: ";
    // Display_Loop(q);

    // // Create a linked list with a loop
    // Node *head = new Node{data : 1, next : nullptr};
    // head->next = new Node{data : 1, next : nullptr};
    // head->next->next = new Node{data : 1, next : nullptr};
    // head->next->next->next = new Node{data : 1, next : nullptr};
    // head->next->next->next->next = head; // Create a loop

    // cout << isHavingLoop(head) << endl;
    // cout << isHavingLoop(q) << endl;
    // cout << endl;

    // // Insert elements into the circular linked list
    // CircularLLInsertAtEnd(head, 1);
    // CircularLLInsertAtEnd(head, 2);
    // CircularLLInsertAtEnd(head, 3);
    // CircularLLInsertAtEnd(head, 4);

    // DisplayCircularLL(head);
    // DisplayCircularLL_Recursion(head, head);
    // cout << endl;

    // CircularLLInsertAtPos(head, 9, 5);
    // DisplayCircularLL(head);

    // DeleteFromCircularLL(head, 0);
    // DisplayCircularLL(head);
}
