# Diagonal Matrix
$$
M = \begin{bmatrix}
       1 & 0 & 0 \\[0.3em]
       0 & 1           & 0 \\[0.3em]
       0           & 0 & 1\\[0.3em]
     \end{bmatrix}
     of \space 3 \times 3 \space size
$$
- we can save the memory by not storing the 0s and only storing the value of `M[i,j]` where `i==j`, i.e, the diagonal values
- for `nxn` size matrix, we can create a linear array(1D) of size `n`, which would contain the diagonal values

1. using `struct`
```cpp
#include <iostream>
using namespace std;

struct Matrix
{
    // int A[n]; //it is compile time size allocation, but we need to allocate the size dynamically to save memeory, hence, allocating the size dynamically in heap
    int *A; // runtine size allocation
    int n;  // dimension
};

void Set(struct Matrix *m, int i, int j, int value)
{
    if (i == j)              // diagonal condition
        m->A[i - 1] = value; // [i-1] as math matrix starts from index 1, but array indexing starts from 0
}

int Get(struct Matrix *m, int i, int j)
{
    if (i == j)
        return m->A[i - 1];
    else
        return 0;
}

void Display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

int main()
{
    struct Matrix m;

    cout << "Enter the dimension of diagonal matrix: ";
    cin >> m.n;
    m.A = new int[m.n];

    Set(&m, 1, 1, 5);
    Set(&m, 2, 2, 6);
    Set(&m, 3, 3, 9);
    Set(&m, 4, 4, 7);

    cout << Get(&m, 1, 2) << endl;
    cout << Get(&m, 2, 2) << endl;
    cout << Get(&m, 3, 2) << endl;

    Display(m.A, m.n);

    delete[] m.A; // deallocate/free the heap memory
}
```
2. using `class`
```cpp
#include <iostream>
using namespace std;

class DiagonalMatrix
{
private:
    int n;
    int *A;

public:
    DiagonalMatrix(int n)
    {
        this->n = n;
        // this->A = new int[n];
        // OR, simply
        A = new int[n];
    }
    void Set(int i, int j, int value);
    int Get(int i, int j);
    void Display();
    ~DiagonalMatrix();
};

void DiagonalMatrix::Set(int i, int j, int value)
{
    if (i == j)
        A[i - 1] = value;
}
int DiagonalMatrix::Get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    else
        return 0;
}
void DiagonalMatrix::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}
DiagonalMatrix::~DiagonalMatrix()
{
    delete[] A;
}
int main()
{
    DiagonalMatrix d(5);
    d.Set(1, 1, 4);
    d.Set(2, 2, 5);
    d.Set(3, 3, 6);
    d.Set(4, 4, 7);

    d.Display();

    cout << d.Get(3, 4) << endl;
    cout << d.Get(3, 3) << endl;
}
```
