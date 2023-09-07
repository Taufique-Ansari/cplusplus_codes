#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &v, int s, int e, int x){
    while(s<=e){
        int mid = s+(e-s)/2;
        if(v[mid] == x){
            return mid;
        }
        else if(v[mid] > x){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

int expoSearch(vector<int> &v,int x){
    int n = v.size();
    if(v[0] == x){
        return 0;
    }
    int i = 1;
    while(i<n && v[i]<=x){
        i *=2;
    }
    return binarySearch(v,i/2,min(i,n-1),x);
}

int main()
{
    vector<int> v = {3,4,5,6,11,13,14,15,56,70};
    int x = 4;
    cout<<expoSearch(v,x);

    return 0;
}