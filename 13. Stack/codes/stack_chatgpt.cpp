// from chatgpt
#include <iostream>
#include <stdexcept>

template <typename T, size_t N>
class Stack
{
private:
    T items[N];
    size_t size;

public:
    // Constructor
    Stack() : size(0) {}

    // Check if the stack is empty
    bool is_empty() const
    {
        return size == 0;
    }

    // Get the size of the stack
    size_t get_size() const
    {
        return size;
    }

    // Push an item onto the stack
    void push(const T &item)
    {
        if (size < N)
        {
            items[size] = item;
            size++;
        }
        else
        {
            throw std::overflow_error("Stack overflow");
        }
    }

    // Pop an item from the stack
    T pop()
    {
        if (size > 0)
        {
            size--;
            return items[size];
        }
        else
        {
            throw std::underflow_error("Stack underflow");
        }
    }

    // Peek at the top item without removing it
    T &peek() const
    {
        if (size > 0)
        {
            return items[size - 1];
        }
        else
        {
            throw std::underflow_error("Stack is empty");
        }
    }
};

int main()
{
    // Create a new stack of integers with a fixed-size array
    Stack<int, 3> stack;

    // Push some items onto the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(3);

    // Peek at the top item
    std::cout << "Top item: " << stack.peek() << std::endl;

    // Pop items from the stack
    while (!stack.is_empty())
    {
        std::cout << "Popped item: " << stack.pop() << std::endl;
    }

    // Check if the stack is empty
    std::cout << "Is the stack empty? " << (stack.is_empty() ? "Yes" : "No") << std::endl;

    return 0;
}
