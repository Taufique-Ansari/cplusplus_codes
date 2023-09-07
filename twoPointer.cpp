#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    int target; cin>>target;
    vector<int> v(n);
    for(auto &i : v){
        cin>>i;
    }
    bool found = false;
    for(int i = 0; i < n; i++){
        int low = i+1, hi = n-1;
        while(low<hi){
            int current = v[i]+v[low]+v[hi];
            if(current == target){
                found = true;
            }
            if(current < target){
                low++;
            }
            else{
                hi--;
            }
        }
    }
    if(found){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    return 0;
}