#include <iostream>

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *n1 = new Node{
        data :
            0,
        next : nullptr
    };

    Node *temp = new Node{
        data : 9,
        next : nullptr
    };

    n1->next = temp;
    std::cout << n1 << std::endl;

    Node *n2 = n1;
    // Node n2 = *n1;
    // Node *n2 = &*n1;
    // Node *&n2 = n1;
    // std::cout << &n2 << std::endl;

    n1 = temp;
    std::cout << n1 << "\t" << n1->data << std::endl;
    std::cout << n2 << "\t" << n2->data << std::endl;
}