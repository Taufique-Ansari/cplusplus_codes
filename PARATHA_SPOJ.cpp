#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> cRanks,int nP, int sol){
    int currPara = 0;
    for(int i = 0; i < cRanks.size(); i++){
        int R = cRanks[i];
        int j=1;
        int timeTaken = 0;

        while(true){
            if(timeTaken + j*R <= sol){
                timeTaken += j*R;
                ++currPara;
                ++j;
            }else{
                break;
            }
        }
        if(currPara >= nP){
            return true;
        }
    }
    return false;
}

int minTimeForOrder(vector<int> cRanks, int nP){
    int s = 0;
    int hR = *max_element(cRanks.begin(),cRanks.end());
    int e = hR*(nP*(nP+1)/2);
    int ans = -1;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(cRanks,nP,mid)){
            cout<<"mid is "<<mid<<endl;
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans;
}

int main()
{
    int T; 
    cin>>T;
    while(T--){
        int nP,nC; 
        cin>>nP>>nC;
        vector<int> cRanks;
        while(nC--){
            int r; cin>>r;
            cRanks.push_back(r);
        }
        cout<<minTimeForOrder(cRanks,nP)<<endl;
    }

    return 0;
}