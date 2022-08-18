#include <iostream>
using namespace std;

class students{
    private:
        long int prn;
    public:
        string Name;
        int rollNo;
        string div;

    void getData(){
        cout<<"Name: ";
        cin>>Name;
        cout<<"Roll no.: ";
        cin>>rollNo;
        cout<<"PRN: ";
        cin>>prn;
        cout<<"Div: ";
        cin>>div;
    }

    void display(){
        cout<<"Name: "<<Name<<endl;
        cout<<"Roll No.: "<<rollNo<<endl;
        cout<<"PRN: "<<prn<<endl;
        cout<<"Div: "<<div<<endl;
    }
};

int main()
{
    int n;
    cout<<"\t\tEnter the No. of Students: ";
    cin>>n;
    students arr[n];
    for(int i = 0; i < n; i++){
        arr[i].getData();
    }cout<<"\n"<<endl;
    for(int i = 0; i < n; i++){
        arr[i].display();
    }
    return 0;
}