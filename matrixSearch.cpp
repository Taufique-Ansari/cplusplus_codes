#include <iostream>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    int a[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }

    int r = 0, c = m - 1;
    int flag = false;
    while (r < n && c >= 0)
    {
        if(a[r][c] == k){
            flag = true;
        }
        if(a[r][c] > k){
            c--;
        }
        else{
            r++;
        }
        
    }
    if(flag){
        cout<<"Element Found";
    }else{
        cout<<"Element not found"<<endl;
    }
    

    return 0;
}