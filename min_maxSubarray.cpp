#include <iostream>
#include<vector>
#include <deque>
using namespace std;

vector<int> solve(vector<int> &v,int k){
	vector<int> ans;
	deque<int> dq;
	deque<int> dq2;

	for(int i = 0 ; i < k; i++){
		while(!dq.empty() && v[i] >= v[dq.back()]){
			dq.pop_back();
		}
		while(!dq2.empty() && v[i] <= v[dq2.back()]){
			dq2.pop_back();
		}
		dq.push_back(i);
		dq2.push_back(i);
	}
	int sum = v[dq.front()]+v[dq2.front()];
	ans.push_back(sum);
	for(int i = k; i < v.size(); i++){
		if(!dq.empty() && i - dq.front() >= k){
			dq.pop_front();
		}
		if(!dq2.empty() && i - dq2.front() >= k){
			dq2.pop_front();
		}

		while(!dq.empty() && v[i] >= v[dq.back()]){
			dq.pop_back();
		}
		while(!dq2.empty() && v[i] <= v[dq2.back()]){
			dq2.pop_back();
		}
		dq.push_back(i);
		dq2.push_back(i);
		int sum = v[dq.front()]+v[dq2.front()];
		ans.push_back(sum);
	}
	return ans;

}

int main() {
	// your code goes here
	vector<int> v = {2,5,-1,7,-3,-1,-2};
	vector<int> a = solve(v,3);
	for(auto i : a){
		cout<<i<<" ";
	}cout<<endl;
	return 0;
}
