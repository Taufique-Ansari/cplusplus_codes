#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// int largestArea(vector<int> a){
//     int n = a.size(), ans = 0, i = 0;
//     stack<int> st;
//     while(i<n){
//         while(!st.empty() && a[st.top()] > a[i]){
//             int h = a[st.top()];
//             st.pop();
//             if(st.empty()){
//                 ans = max(ans,h*i);
//             }
//             else{
//                 int len = i - st.top() - 1;
//                 ans = max(ans,h*len);
//             }
//         }
//         st.push(i);
//         i++;
//     }
//     return ans;
// }


vector<int> prevSmall(vector<int> &a){
    vector<int> ans(a.size());
    stack<int> st;
    st.push(-1);
    
    for(int i = 0; i < a.size(); i++){
        while(!st.empty() && a[st.top()] >= a[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> nextSmall(vector<int> &a){
    vector<int> ans(a.size());
    stack<int> st;
    st.push(-1);
    
    for(int i = a.size()-1; i >= 0; i--){
        while(!st.empty() && a[st.top()] >= a[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestArea(vector<int> &a){
    vector<int> prev = prevSmall(a);
    vector<int> next = nextSmall(a);

    int maxArea = INT_MIN;
    int size = a.size();
    for(int i = 0; i < a.size(); i++){
        int h = a[i];
        if(next[i] == -1){
            next[i] = size;
        }
        int w = next[i] - prev[i] - 1;
        int area = h*w;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}

int main()
{
    vector<int> a = {2,1,5,6,2,3};
    cout<<largestArea(a);

    return 0;
}