#include <iostream>
#include <queue>
using namespace std;

class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:

    Stack(){
        N = 0;
    }

    // void push(int val){
    //     q2.push(val);
    //     N++;
    //     while(!q1.empty()){
    //         q2.push(q1.front());
    //         q1.pop();
    //     }
    //     queue<int> temp = q1;
    //     q1 = q2;
    //     q2 = temp;
    // }

    void push(int val){
        q1.push(val);
        N++;
    }

    // void pop(){
    //     q1.pop();
    //     N--;
    // }

    //pop is going to be costly in 2nd method
    void pop(){
        if(q1.empty()){
            return;
        }
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    // int top(){
    //     return q1.front();
    // }

    int top(){
        if(q1.empty()){
            return -1;
        }
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        q2.push(ans);
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }

    int size(){
        return N;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size();



    return 0;
}