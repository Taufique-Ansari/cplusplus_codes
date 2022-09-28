#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestArea(vector<int> a){
    int n = a.size(), ans = 0, i = 0;
    stack<int> st;
    while(i<n){
        while(!st.empty() && a[st.top()] > a[i]){
            int h = a[st.top()];
            st.pop();
            if(st.empty()){
                ans = max(ans,h*i);
            }
            else{
                int len = i - st.top() - 1;
                ans = max(ans,h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main()
{
    vector<int> a = {2,1,5,6,2,3};
    cout<<largestArea(a);

    return 0;
}