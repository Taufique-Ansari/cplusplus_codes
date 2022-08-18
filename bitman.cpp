#include <iostream>
using namespace std;

int getBit(int n, int i)
{
    return ((n & (1<<i)) != 0);
}

int setBit(int n, int i)
{
    return (n | (1<<i));
}

int clearBit(int n, int i)
{
    int mask = ~(1<<i);
    return (n & mask);
}

int updateBit(int n,int i,int value)
{
    int mask = ~(1<<i);
    n = n & mask;
    return (n | (value<<i));
}

int toogleBit(int n, int i)
{
    return (n xor (1<<i));
}

int computeXOR(int n)
{
    if(n % 4 == 0)
        return n;
    if(n % 4 == 1)
        return 1;
    if(n % 4 == 2)
        return n + 1;
    else
        return 0;
}

int main()
{
    // cout<<getBit(8,3)<<endl;        //1
    // cout<<setBit(8,2)<<endl;        //12
    // cout<<clearBit(5,0)<<endl;      //4
    // cout<<updateBit(5,1,1)<<endl;   //7
    // cout<<toogleBit(8,1)<<endl;     //10
    cout<<computeXOR(6)<<endl;
}