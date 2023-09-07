#include <iostream>
using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen(_Filename:"input.txt", _Mode:"r", _File: stdin);
//     freopen(_Filename:"output.txt", _Mode:"w", _File: stdout);
// #endif

    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Matrix is:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int x;
    cin>>x;
    bool flag = false;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == x)
            {
                cout<<i<<j<<endl;
                flag = true;
            }
            
        }
        
    }

    if(flag){
        cout<<"Element found\n";
    }else{
        cout<<"Element not found\n";
    }

return 0;
}