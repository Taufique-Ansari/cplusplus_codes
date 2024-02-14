#include <iostream>
#include <vector>

using namespace std;

void combinationSumHelper(vector<int>& candidates, int target, vector<int>&v, vector<vector<int> > &ans, int index){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            v.push_back(candidates[i]);
            combinationSumHelper(candidates,target-candidates[i],v,ans,i);
            v.pop_back();
        }
    }

int main()
{
    vector<int> candidates{2,3,6,7};
    int target = 7;
    vector<vector<int> > ans;
    vector<int> v;
    combinationSumHelper(candidates,target,v,ans,0);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0; j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}