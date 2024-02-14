#include <iostream>
using namespace std;

class NStack{
    int *a,*top,*next;
    int n;
    int size;
    int freeSpot;
    public:
        NStack(int _n, int _s):n(_n),size(_s){
            freeSpot = 0;
            a = new int[size];
            top = new int[n];
            next = new int[size];

            for(int i = 0; i < n; i++){
                top[i] = -1;
            }

            for(int i = 0; i < size; i++){
                next[i] = i+1;
            }
            next[size-1] = -1;
        }

        bool push(int X, int m){
            if(freeSpot == -1){
                return false;
            }
            int index = freeSpot;
            freeSpot = next[index];
            a[index] = X;
            next[index] = top[m-1];
            top[m-1] = index;
            return true;
        }

        int pop(int m){
            if(top[m-1] == -1){
                return false;
            }
            int index = top[m-1];
            top[m-1] = next[index];
            int popped = a[index];
            next[index] = freeSpot;
            freeSpot = index;
            return popped;
        }

        ~NStack(){
            delete[] a;
            delete[] top;
            delete[] next;
        }

};

int main()
{
    NStack* n = new NStack(6,3);
    cout<<n->push(5,1);
    cout<<n->push(10,2);
    cout<<n->push(6,1);
    cout<<n->pop(1);

    
    
    return 0;
}