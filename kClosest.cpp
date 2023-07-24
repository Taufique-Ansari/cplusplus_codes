#include <iostream>
#include <vector>
using namespace std;

int lowerbound(vector<int> nums, int x){
    int s = 0;
    int e = nums.size()-1;
    int ans = e;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(nums[mid] >= x){
            ans = mid;
            e = mid-1;
        }
        else if(nums[mid] < x){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

vector<int> kClosest(vector<int> &nums, int k,int x){
    int h = lowerbound(nums,x);
    int l = h-1;
    while(k--){
        if(l<0){
            h++;
        }
        else if(h>=nums.size()){
            l--;
        }
        else if(x-nums[l] > nums[h]-x){
            h++;
        }
        else{
            l--;
        }
    }
    return vector<int>(nums.begin()+l+1,nums.begin()+h);
}


//---------------- TWO POINTER APPROCH------------------//
// vector<int> kClosest(vector<int> &nums, int k,int x){
//     int l=0;
//     int h = nums.size()-1;
//     while(h-l>=k){
//         if(x-nums[l] > nums[h]-x){
//             l++;
//         }
//         else{
//             h--;
//         }
//     }
//     return vector<int>(nums.begin()+l,nums.begin()+h+1);
// }

int main()
{
    vector<int> nums = {12,16,22,30,35,39,42,45,48,50,53,55,56};
    int k = 4;
    int x = 35;

    vector<int> ans = kClosest(nums,k,x);
    for(auto i : ans){
        cout<<i<<" ";
    }


    return 0;
}