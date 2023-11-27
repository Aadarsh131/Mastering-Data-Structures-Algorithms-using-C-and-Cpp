# Stack
implementation using-
- Array
- Linked List

**NOTE:** insert from the side where the time complexity remains `O(1)`

1. Using Array
    ```cpp
    #include <bits/stdc++.h>
    using namespace std;

    struct Stack
    {
        int size;
        int top;
        char *s;
    };

    void push(Stack &s, int value)
    {
        if (s.top == s.size - 1)
            cout << "stack is full" << endl;
        else
        {
            s.top++;
            s.s[s.top] = value;
        }
    }

    void pop(Stack &s)
    {
        if (s.top == -1)
            cout << "stack is empty" << endl;
        else
        {
            s.s[s.top] = ' ';
            s.top--;
        }
    }

    void peek(Stack &s, int pos)
    {
        if (pos <= 0)
            cout << "cannot index zero or negative number" << endl;
        else if (pos > s.top + 1)
        {
            cout << "connot peek beyond the stack size" << endl;
        }
        else
        {
            cout << s.s[s.top - pos + 1] << endl;
        }
    }

    void display(Stack &s)
    {
        for (int i = s.size - 1; i >= 0; i--)
        {
            cout << s.s[i] << " ";
        }
        cout << endl;
    }

    int main()
    {
        Stack st;
        cout << "Enter the size of stack" << endl;
        // scanf("%d", &st.size);
        cin >> st.size;
        st.s = new char[st.size];
        st.top = -1;

        push(st, 'c');
        push(st, 'd');
        push(st, 't');
        push(st, 't');

        display(st);

        pop(st);
        display(st);

        peek(st, 3);
    }
    ```
2. using linkedList
    ```cpp
    printf("Easier than you think");
    ```