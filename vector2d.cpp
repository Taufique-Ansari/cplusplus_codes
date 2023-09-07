#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    vector< vector<int> > vect{{3, 5, 1},{4, 8, 6},{7, 2, 9}};

    int m = vect.size();
    int n = vect[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout<<vect[i][j]<<" ";
        }cout<<endl;
    }

    
    for(int i = 0; i < m; i++){
        sort(vect[0].rbegin(),vect[0].rend());
        for(int j = 0; j < n; j++){
            cout<<vect[i][j]<<" ";
        }cout<<endl;
    }
}