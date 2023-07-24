#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpan(vector<int> prices){
    vector<int> ans;
    stack<pair<int,int> > s;
    for(int i = 0; i < prices.size(); i++){
        int day = 1;
        while(!s.empty() && s.top().first <= prices[i]){
            day += s.top().second;
            s.pop();
        }
        s.push(make_pair(prices[i],day));
        ans.push_back(day);
    }
    return ans;
}

int main()
{
    vector<int> a = {100,80,60,70,60,75,85};
    vector<int> res = stockSpan(a);
    for(auto i : res){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}