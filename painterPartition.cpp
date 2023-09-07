#include <iostream>
#include <numeric>
using namespace std;

//Given an array which represents the size of boards to be painted by k painters such that the time taken is minimum, each painters takes 1 unit of time to paint 1 unit length of the board
// the assigning of the painters should be continous.
//n is no of boards and k is no of painters

bool isPossible(int arr[], int n, int k, int sol){
    int timeTaken = 0;
    int counter = 1;
    
    for(int i = 0;i < n; i++){
        if(arr[i] > sol) return false;
        if(timeTaken + arr[i] > sol){
            timeTaken = arr[i];
            counter++;
            if(counter > k) return false;
        }else{
            timeTaken += arr[i];
        }
    }
    return true;
}

int painterPartition(int arr[], int n, int k){
    int s = 0;
    int e = accumulate(arr,arr+n,0);
    int ans = -1;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(arr,n,k,mid)){
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {5,10,30,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout<<"Minimum time taken by "<<k<<" painters to paint the wall is "<<painterPartition(arr,n,k)<<endl;;

    return 0;
}