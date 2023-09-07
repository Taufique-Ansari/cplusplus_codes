#include <iostream>

using namespace std;

int bitwise(int a){
    int m = a;
    int mask = 0;
    if(a == 0){
        return 1;
    }
    while(m!=0){
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    int ans = ~a & mask;
    return ans;
}

int main()
{
    cout<<bitwise(0);

    return 0;
}