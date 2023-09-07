#include <iostream>
using namespace std;

// void increment(int &a){
//     a++;
// }

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    // int a = 10;
    // int *aptr = &a;
    // cout<<*aptr<<endl;
    // *aptr = 20;

    // cout<<a<<endl;

    // int arr[] = {10,20,30,40};
    // int *ptr = arr;
    // for(int i = 0; i < 4; i++)
    // {
    //     cout<<*ptr<<endl;
    //     ptr++;
    // }


    // POINTER TO POINTER

    // int a = 10;
    // int *p = &a;

    // cout<<*p<<endl;

    // int **q = &p;
    // cout<<*q<<endl;
    // cout<<**q<<endl;

    //IMPLEMENTATION

    // int a = 2;
    // increment(a);
    // cout<<a<<endl;

    //SWAP

    int a = 4;
    int b = 9;

    swap(a,b);
    cout<<a<<" "<<b<<endl;

    return 0;
}