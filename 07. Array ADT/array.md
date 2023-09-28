# Array ADT
- it constitutes the basic array datastructure and the operations on it
## 2 ways of initializing array ***(Size allocation at runtime vs at compile time)***

```cpp
int A[20]; //size initilaization at compile time
```

```cpp
int *A;
A = new int[size]; //size initialization at runtime
```

## Array, its size and length(actual items present denotes length)
```cpp
#include <iostream>
using namespace std;

struct array{ //Array basic 2 properties
    int *A;
    int size;
    int length;
};    
void Display(int *A,int size){
    for(int i=0;i <size; i++){
        cout << A[i] << "\t";
    }
}
int main()
{
    struct array arr;
    cout << "Enter the size of array (SIZE)" << endl;
    cin >> arr.size;
    arr.length = 0;

    arr.A = new int[arr.size]; //initializing on heap

    cout << "Enter how many elements to enter for the max array size (LENGTH): " << arr.size << endl;
    
    cin >> arr.length;

    cout << "Enter "<< arr.length << " values" << endl;
    for(int i=0;i<arr.length;i++){
        cin >> arr.A[i];
    }

    Display(arr.A,arr.size);
    return 0;

}
```