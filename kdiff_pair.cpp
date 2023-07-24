#include <iostream>
#include <set>
using namespace std;

int binarySearch(vector<int> &v, int s, int t){
    int e = v.size()-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(v[mid] == t){
            return mid;
        }else if(v[mid] > t){
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return -1;
}

int bs_method(vector<int> &v, int k){
    sort(v.begin(),v.end());
    int n = v.size()-1;
    set<pair<int,int> > ans;
    for(int i = 0; i < n; i++){
        if(binarySearch(v,i+1,v[i]+k)){
            ans.insert(make_pair(v[i],v[i]+k));
        }
    }
    return ans.size();
}

// int kdiff(vector<int> &v, int k){
//     sort(v.begin(),v.end());
//     set<pair<int,int> > ans;
//     int n = v.size()-1;
//     int i = 0;
//     int j = 1;
//     while(i<=n && j<=n){
//         int diff = abs(v[i]-v[j]);
//         if(diff == k && i!=j){
//             ans.insert(make_pair(v[i],v[j]));
//             j++;
//         }
//         else if(diff > k){
//             i++;
//         }
//         else{
//             j++;
//         }
//     }
//     return ans.size();
// }

int main()
{
    vector<int> v = {1,2,3,4,5};
    int k = 1;
    cout<<"ans is "<<bs_method(v,k);

    return 0;
}