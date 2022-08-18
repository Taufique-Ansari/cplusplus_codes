#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    if(a > b) {
        cout<<"a is greater than b";
    }else if(a > c) {
        cout<<"a is the greatest number";
    }else if(b > c){
        cout<<"b is greatest number";
    }else{
        cout<<"c is the greatest of all";
    }
}