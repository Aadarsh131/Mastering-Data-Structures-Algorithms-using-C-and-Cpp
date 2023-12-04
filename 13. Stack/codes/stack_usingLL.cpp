#include <iostream>

struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    Node *head = nullptr;
};

void push(Stack *s, int elem)
{
    // works for both empty and non-empty
    Node *newNode = new Node;
    newNode->data = elem;
    newNode->next = s->head;
    s->head = newNode;

    // this case would never be met, not because of the OOM killer would not let us to do so, but because, if memory do overflows (in bare metal case), then, `new` would throw an error beforehand, meaning we would have never reached this code, so the code commented code below is NOT correct (A MISTAKE IN THE TUTORIAL)
    /*
    if (newNode == nullptr) // haulting if the heap is full
    {
        std::cout << "Cannot insert, the heap storage of your RAM might be full" << std::endl;
        return;
    }
   */
}

int pop(Stack *s)
{
    if (s->head)
    {
        Node *temp = s->head;
        s->head = s->head->next;
        // temp->next = nullptr;
        return temp->data;

        delete temp->next; // is it reqd?
        delete temp;
    }
    return -1; // operation unsuccessful
}

void Display(Stack *s)
{
    Node *temp = s->head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    delete temp; // maybe no need to delete, as the temp is already null at this point (i,e, it is pointing to noting, so the loss of the pointer would NOT create a dangling reference)
}

int main()
{
    Stack *s1 = new Stack; // or Stack *s1;
    push(s1, 4);
    push(s1, 5);
    push(s1, 8);
    Display(s1);

    push(s1, 6);
    push(s1, 9);
    push(s1, 1);
    Display(s1);

    std::cout << pop(s1) << std::endl;
    std::cout << pop(s1) << std::endl;
    std::cout << pop(s1) << std::endl;
    std::cout << pop(s1) << std::endl;
    std::cout << pop(s1) << std::endl;
    std::cout << pop(s1) << std::endl;
    std::cout << pop(s1) << std::endl;
    Display(s1);
}