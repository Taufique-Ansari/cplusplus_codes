#include <iostream>
using namespace std;

//function overloading
class test
{
    public:
        void func(){
            cout<<"This is a function with no argument"<<endl;
        }
        void func(int x){
            cout<<"This is a function with int argument"<<endl;
        }
        void func(double x){
            cout<<"This is a function with bool argument"<<endl;
        }
};

int main()
{
    test obj;
    obj.func();
    obj.func(2);
    obj.func(3.14);
}