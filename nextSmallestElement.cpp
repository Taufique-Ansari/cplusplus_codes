#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<int> v {2,1,4,3};
    vector<int> ans(v.size());
    stack<int> st;
    st.push(-1);
    for(int i = v.size()-1; i >= 0; i--){
        while(st.top() >= v[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(v[i]);
    }

    // This is for previous smallest element, just reverse the loop
    // for(int i = 0; i < v.size(); i++){
    //     while(st.top() >= v[i]){
    //         st.pop();
    //     }
    //     ans[i] = st.top();
    //     st.push(v[i]);
    // }

    for(auto i : ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}