#include <iostream>
using namespace std;

int woodCuted(int arr[], int n, int sol){
    int cutValue = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > sol){
            cutValue += arr[i]-sol;
        }
    }
    return cutValue;
}

int findHeight(int arr[], int n, int rw){
    int s = 0;
    int mV = INT_MIN;
    for(int i = 0; i < n; i++){
        mV = max(mV,arr[i]);
    }
    int e = mV;
    int ans = -1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(woodCuted(arr,n,mid) >= rw){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {30,13,20,10};
    int reqWood = 7;
    int n = 4;

    cout<<findHeight(arr,n,reqWood);

    return 0;
}