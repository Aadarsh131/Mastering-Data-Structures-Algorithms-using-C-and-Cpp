#include <iostream>
#include <array>

using namespace std;
int main()
{
    int *A[3];
    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];

    A[1][3] = 14;
    cout << A[1][3] << endl;

    cout << typeid(A).name() << endl; //PPi (pointer to Pointer Int)
    cout << typeid(A[0]).name() << endl; //Pi (Pointer to int)
}