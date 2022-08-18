#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > ans;

void permute(vector<int> &a, int idx){
    if(idx == a.size()){
        ans.push_back(a);
        return;
    }
    for(int i = idx; i < a.size(); i++){
        swap(a[i],a[idx]);
        permute(a,idx+1);
        swap(a[i],a[idx]);
    }
    return;
}
int32_t main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a)
        cin>>i;
    // permute(a,0);
    sort(a.begin(),a.end());
    do{
        ans.push_back(a);
    }while(next_permutation(a.begin(),a.end()));
    for(auto v : ans){
        for(auto i : v)
            cout<<i<<" ";
            cout<<"\n";
    }
}



























// void permute(int arr[], int idx, int n){
//     if(idx == n){
//         for(int i = 0; i < n; i++){
//             cout<<arr[i]<<" ";
//         }cout<<endl;
//         return;
//     }

//     for(int i = idx; i < n; i++){
//         swap(arr[i],arr[idx]);
//         permute(arr,idx+1,n);
//         swap(arr[i],arr[idx]);
//     }

//     return;
// }

// int main()
// {
//     int n;
//     cin>>n;

//     int arr[n];
//     for(int i = 0; i < n; i++){
//         cin>>arr[i];
//     }

//     permute(arr,0,n);
    
//     return 0;
// }