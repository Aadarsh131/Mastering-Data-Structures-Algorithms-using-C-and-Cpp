# References in C++
```cpp
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int &r = a; //r is the ref to a, i.e, in layman's term another name for a 
    //NOTE: references must be initialized while declaration
    // int &r will give an error
    cout << &r << endl;
    r++;
    cout << a << endl;
}
```