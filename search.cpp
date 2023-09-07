#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            cout<<key<<" is at "<<i + 1<<" position";
        }
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;

    cout<<linearSearch(arr,n,key);
}