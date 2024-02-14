#include <iostream>
#include <vector>
using namespace std;

// Given an array of positions of stalls placed at a distance,
// task is to place k no. of cows in such a way that the minimum distance between them is the maximum possible

bool isPossible(vector<int> &stalls, int k, int sol){
    int pos = stalls[0]; // first cow is placed
    int counter = 1;
    for(int i = 1; i < stalls.size(); i++){
        if(stalls[i] - pos >= sol){
            counter++;
            pos = stalls[i]; //second is placed
        }
        if(counter == k) return true;
    }
    return false;
}

int placeCows(vector<int> &stalls, int k){
    int s = 0; 
    int e = stalls[stalls.size()-1] - stalls[0]; //this will be the max distance possible when 2 cows are placed
    int ans = -1;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(stalls,k,mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1; 
        }
    }
    return ans;
}

int main()
{
    vector<int> stalls = {1,2,4,8,9};
    int k = 3;

    cout<<"The cows are placed at a minimum distance of "<<placeCows(stalls,k);

    return 0;
}