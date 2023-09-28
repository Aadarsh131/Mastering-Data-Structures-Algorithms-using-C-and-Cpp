#include <iostream>
using namespace std;

struct array{
    int A[20];
    int size;
    int length;
};    
void Display(int A[],int size){
    for(int i=0;i <size; i++){
        cout << A[i] << "\t";
    }
}
int main()
{
    struct array arr = {{1,2,3,4,5},20,5};

    Display(arr.A,arr.size);
    return 0;


}