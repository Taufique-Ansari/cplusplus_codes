#include <iostream>
#include <string>
#include <stack>
using namespace std;

// #Iss question me check karna hai ke kitne valid parenthesis hai given string me 
// #Approch: 
//     stack me pahle -1 push kar do to find the len agar starting me koye valid parenthesis hai toh uske liye,
//     Traverse string agar open bracket hai toh uska index stack me push kardo,
//     or agar closing bracket hai toh we assume ke uska open bracket bhi stack me hai toh usko pop kardo.
//     Agar pop karne ke bad stack empty ho jata hai toh uska matlab hai ke woh closing bracket ke liye koye open braket nahi tha. Toh iska matlab abb hum jo position pe hai waha tak koye valid parenthesis nahi hai or stack bhi empty hai toh we push the current index in the stack, 
//     Or agar stack empty nahi hai toh calculate the len of the parenthesis, aur uske sath sath max length jo abhi tak mile hai usko bhi update karte raho kyuki humko max/kitne valid parenthesis hai wo return karna hai

int longestValidParenthesis(string s){
    int len = 0, maxLen = 0;
    stack<int> st;
    st.push(-1);
    int i = 0;

    while(i < s.size()){
        if(s[i] == '('){
            st.push(i);
        }else{
            st.pop();
            if(!st.empty()){
                len = i - st.top();
                maxLen = max(len,maxLen);
            }
            else{
                st.push(i);
            }
        }
        i++;
    }
    return maxLen;
}

int main()
{
    string s = "(()))())(";
    cout<<longestValidParenthesis(s);

    return 0;
}