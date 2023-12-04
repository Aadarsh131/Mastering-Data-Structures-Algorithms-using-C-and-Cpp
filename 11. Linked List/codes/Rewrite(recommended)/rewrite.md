### Different ways to store one pointer data to another 
```cpp
Node *n1 = new Node
{
    data: 3,
    next: nullptr
};

Node *n2 = n1; //easiest and recommended
Node n2 = *n1;
Node *n2 = &*n1;
Node *&n2 = n1; //working with references, hence not recommended at all
Node **n2 = &n2;
```
I unknowingly, started learning it the Wrong way (using the references ``Node *&n2 = n1``).   
But, as I progressed (learned it from Rust), I learnt it was indeed the worst idea, because multiple references to the same data can cause `Data Race` if you dont know what you are doing.

So, a Rewrite to all the previous [SinglyAndCircularLinkedList](../Depricated(bad%20way)/SinglyAndCircularLinkedList.md) and [DoublyLinkedList](../Depricated(bad%20way)/doublyLinkedList.cpp) codes would be coming using the recommended way
