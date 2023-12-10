#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int capacity;
    char *op;
    int top;
};

// considered only 4 operators: +,-,* and / (no unary)
bool isOperator(char c)
{
    // not considering unary operators
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    else
        return false;
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
}

string toPostfix(Stack &stack, string s)
{
    string postfixExp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isOperator(s[i]))
        {
            if (stack.top == -1) // initial stack push (when empty)
            {
                stack.op[stack.top + 1] = s[i]; // push
                stack.top++;
            }
            else if (precedence(s[i]) > precedence(stack.op[stack.top]))
            {
                stack.op[stack.top + 1] = s[i]; // push
                stack.top++;
            }
            else
            {
                while (precedence(s[i]) <= precedence(stack.op[stack.top]))
                {
                    postfixExp += stack.op[stack.top];
                    stack.op[stack.top] = ' '; // pop
                    stack.top--;
                    if (stack.top == -1)
                        break;
                }
                stack.op[stack.top + 1] = s[i]; // push
                stack.top++;
            }
        }
        else
        {
            postfixExp += s[i];
        }
    }
    while (stack.top != -1)
    {
        postfixExp += stack.op[stack.top];
        stack.top--;
    }
    return postfixExp;
}

int main()
{
    string infixExp = "a+b*c-d/e";

    Stack stack;
    stack.capacity = infixExp.length();
    stack.top = -1;
    stack.op = new char[stack.capacity];

    cout << toPostfix(stack, infixExp);
}