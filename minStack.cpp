#include <iostream>
using namespace std;

// #LEETCODE QUESTION MIN STACK, TO MAKE STACK USING CLASS THAT TAKES MAX O(1) TIME FOR ANY OPERATION

class minStack{
    public:
    vector<pair<int,int> > v;
    void push(int val){
        if(v.empty()){
            pair<int,int> p = make_pair(val,val);
            v.push_back(p);
        }
        else{
            pair<int,int> p;
            p.first = val;
            p.second = min(val,v.back().second);
            v.push_back(p);
        }
    }

    void pop(){
        v.pop_back();
    }

    int getVal(){
        return v.back().first;
    }

    int getMin(){
        return v.back().second;
    }
};

int main()
{
    minStack* m = new minStack();
    m->push(1);
    m->push(2);  
    m->push(3);
    m->pop();
    cout<<m->getVal()<<endl;
    cout<<m->getMin();

    return 0;
}