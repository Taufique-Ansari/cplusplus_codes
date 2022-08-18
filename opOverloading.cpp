#include <iostream>
using namespace std;

//operator overloading
class Complex
{
    private:
        int real,img;
    public:
        Complex(int r = 0, int i = 0){
            real = r;
            img = i;
        }
        Complex operator + (Complex const &obj){
            Complex res;
            res.real = real + obj.real;
            res.img = img + obj.img;
            return res;
        }

        void display(){
            cout<<real<<" i"<<img<<endl;
        }
};

int main()
{
    Complex a(12,7);
    Complex b(11,7);
    Complex c = a+b;
    
    c.display();
    return 0;
}