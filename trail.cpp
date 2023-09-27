#include <iostream>
using namespace std;

int main()
{
    // int a = 1;
    // int A[4][3];
    // for (int i = 0; i <= 3; i++)
    // {
    //     for (int j = 0; j <= 2; j++)
    //     {
    //         A[i][j] = a;
    //         a++;
    //     }
    // }
    // for (int i = 0; i <= 3; i++)
    // {
    //     for (int j = 0; j <= 2; j++)
    //     {
    //         cout << *(*(A + i) + j) << ' ' << *(A + i) + j << '\t';
    //         // cout << A[i][j] << '\t';
    //     }
    //     cout << endl;
    // }
    // // cout << *(*(A + 2) + 3);
    // cout << A << endl;
    // return 0;

    int array[5][2] = {{1, 2}, {3, 4}, {5,6}, {7,8}};
    int(*p)[2];
    p = array;

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << array[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    cout << *p[0] << '\t' << *p[1] << '\t' << *p[2] << '\t' << *p[3];
    // printf("The address of array[0][0] is %p \n",&array[0][0]);
    // printf("The address of *p is %p \n",*p);

    // printf("The address of array[1][0] is %p \n",&array[1][0]);
    // printf("The address of *(p+1) is %p \n",*(p+1));

    // printf("The value of array[0][0] is %d \n",array[0][0]);
    // printf("The value of **p is %d \n",**p);

    // printf("The value of array[0][1] is %d \n",array[0][1]);
    // printf("The value of *((*p)+1) is %d \n",*((*p)+1));

    return 0;
}