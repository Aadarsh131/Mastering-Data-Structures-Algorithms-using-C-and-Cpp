# Recursion with global and static variables

## using global variable
```cpp
#include <iostream>
int x = 0;
int foo(int n)
{
    if (n > 0)
    {
        x++;
        return foo(n - 1) + x;
    }
    return 0;
}
int main()
{
    printf("%d\n", foo(5));
    return 0;
}
```
> Output: 25


## using static variable
```cpp
#include <iostream>
int foo(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return foo(n - 1) + x;
    }
    return 0;
}
int main()
{
    printf("%d\n", foo(5));
    return 0;
}
```
> Output: 25

> NOTE: while descending phase(returning phase) of the recursion both variables static and global will have only one copy throughout the program, and hence the `present value of x` will be used, i.e, 5 in our case

## using local variable
```cpp
#include <iostream>
int foo(int n)
{
    if (n > 0)
    {
        return foo(n - 1) + n;
    }
    return 0;
}
int main()
{
    printf("%d\n", foo(5));
    return 0;
}
```
> Output: 15 (This time `n` is variable)

