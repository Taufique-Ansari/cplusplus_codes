#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> v,int target, int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(v[mid] == target){
            return mid;
        }
        if(mid-1 >= 0 && v[mid-1] == target){
            return mid-1;
        }
        if(mid+1 <= n && v[mid+1] == target){
            return mid+1;
        }

        if(target > v[mid]){
            s = mid+2;
        }
        else{
            e = mid-2;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(10);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    cout<<"ans is"<<binarySearch(v,6,v.size());
    return 0;
}