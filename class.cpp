#include <iostream> 
using namespace std;

class student{
    string name;
    public:
    // string name;
    int age;
    bool gender;

    student(){
        cout<<"Default constructor"<<endl;
    }//Default constructor;

    student(string s, int a, int g){
        cout<<"Parameterised constructor"<<endl;
        name = s;
        age = a;
        gender = g;
    }//parameterised constructor    

    student(student &a){
        cout<<"Copy constructor"<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }//Copy constructor
    //There are two types of copy constructor 1.default and 2.that we make
    //default one does shallow copying i.e it just copy the data of the object leaving the pointer that points it
    //the 2nd one does the deep copying as it copies both the data as well as the pointer pinting that data.

    ~student(){
        cout<<"Destructor called"<<endl;
    }

    void setName(string s){
        name = s;
    }

    void getName(){
        cout<<name<<endl;
    }

    void printInfo(){
        cout<<"Name = ";
        cout<<name<<endl;
        cout<<"Age = ";
        cout<<age<<endl;
        cout<<"Gender = ";
        cout<<gender<<endl;
    }

    bool operator == (student &a){
        if(name == a.name && age == a.age && gender == a.gender){
            return true;
        }
        return false;
    }//this is called operator overloading
    //Operator Overloading: The process of making an operator to exhibit 
    //different behaviours in different instances is known as operator overloading.
};

int main()
{
    // student arr[3];
    // for(int i = 0; i <3; i++){
    //     string s;
    //     cout<<"Name = ";
    //     cin>>s;
    //     arr[i].setName(s);
    //     cout<<"Age = ";
    //     cin>>arr[i].age;
    //     cout<<"Gender = ";
    //     cin>>arr[i].gender;
    // }

    // for(int i = 0; i < 3; i++){
    //     arr[i].printInfo();
    // }

    student a("taufique",18,1);
    student b; //when we don't give it any input it by defaults calls the default constructor
    student c = a;
    // student c;

    if(c==a){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }

    return 0;
    
}