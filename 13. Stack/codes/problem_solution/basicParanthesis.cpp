#include <iostream>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *s;
};

void push(Stack &s, char val)
{
    s.top++;
    s.s[s.top] = val;
}

void pop(Stack &s)
{
    if (s.top >= 0)
    {
        s.s[s.top] = ' ';
        s.top--;
    }
}

bool isBalance(Stack &s, char *exp)
{
    for (int i = 0; i < s.size; i++)
    {
        if (exp[i] == '(')
        {
            push(s, '(');
        }
        else if (exp[i] == ')')
        {
            if (s.top < 0) // if stack is empty
            {
                return false;
            }
            pop(s);
        }
    }
    return (s.top == -1) ? true : false;
}

int main()
{
    Stack s1;
    char *exp = "(a)+(c+d)";
    s1.top = -1;
    s1.size = strlen(exp);
    s1.s = new char[s1.size];

    isBalance(s1, exp) ? std::cout << "Balanced" : std::cout << "NOT Balanced";
}