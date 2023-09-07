#include <iostream>
using namespace std;

void linearSearch(int arr[],int key){
    for(int i = 0; i < 7; i++){
        if(arr[i] == key){
            cout<<i<<endl;
        }
    }
}

int main()
{
    int arr[] = {2,4,6,8,10,12,15};
    linearSearch(arr,6);

    return 0;
}