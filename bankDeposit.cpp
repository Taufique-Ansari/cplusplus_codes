#include <iostream>
using namespace std;

class bankDeposit
{
    int principle;
    int year;
    float rInterest;
    float returnValue;
    public:
        bankDeposit();
        bankDeposit(int p, int y, float r){
            principle = p;
            year = y;
            rInterest = r;
            returnValue = principle;
            for (int i = 0; i < y; i++)
            {
                returnValue = returnValue * (1+rInterest);
            }
        }
        bankDeposit(int p, int y, int r){
            principle = p;
            year = y;
            rInterest = float(r)/100;
            returnValue = principle;
            for (int i = 0; i < y; i++)
            {
                returnValue = returnValue * (1+rInterest);
            }
        }
        void display(){
            cout<<"Your investment was Rs."<<principle<<endl<<"Return on investment after "<<year<<" year will be "<<returnValue<<endl;
        }
};

int main()
{   
    int x,y,R;
    float z;
    cout<<"Enter the principle amount,time period and rate of interest respectively: ";
    cin>>x>>y>>z;
    bankDeposit bankDeposit1 =  bankDeposit(x,y,z);
    bankDeposit1.display();

    cout<<"Enter the principle amount,time period and rate of interest respectively: ";
    cin>>x>>y>>R;
    bankDeposit bankDeposit2 = bankDeposit(x,y,R);
    bankDeposit2.display();
    return 0;
}