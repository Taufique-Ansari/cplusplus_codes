#include <iostream>
using namespace std;

int main()
{
    string s = "taaaufffiqqqqueeeee";
    int n = s.size();

    char ans[100];
    ans[0] = s[0];
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(s[i] != s[i-1])
        {
            ans[cnt] = s[i];
            cnt++;
        }
    }

    cout<<ans<<endl;
}