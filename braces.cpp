#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    bool ans = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.top() == '('){
                st.pop();
                ans = true;
            }
            else{
                return false;
            }
        }
        else if(s[i] == ']'){
            if(st.top() == '['){
                st.pop();
                ans = true;
            }
            else{
                return false;
            }
        }
        else if(s[i] == '}'){
            if(st.top() == '{'){
                st.pop();
                ans = true;
            }
            else{
                return false;
            }
        }
    }
    return ans;
}

int main(){
    string s;
    getline(cin,s);
    cout<<isValid(s);
}