#include <iostream>
using namespace std;

class KQueue{
    public:
        int n,k,freeSpot;
        int *arr,*front,*rear,*next;

        KQueue(int _n, int _k):n(_n),k(_k) {
            arr = new int[n];
            next = new int[n];
            front = new int[k];
            rear = new int[k];

            for(int i = 0; i < k; i++){
                front[i] = rear[i] = -1;
            }

            for(int i = 0; i < n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
        }

        bool push(int x, int qi){
            if(freeSpot == -1){
                return false;
            }

            int index = freeSpot;
            freeSpot = next[index];

            if(front[qi] == -1){
                front[qi] = index;
            }
            else{
                front[rear[qi]] = index;
            }

            next[index] = -1;

            rear[qi] = index;
            arr[index] = x;
            return true;
        }

        int pop(int qi){
            if(front[qi] == -1){
                return -1;
            }

            int index = front[qi];
            front[qi] = next[index];
            next[index] = freeSpot;
            freeSpot = index;

            return arr[index];
        }

        // void print(int qi){
        //     if(front[qi] == -1){
        //         cout<<"Queue is empty"<<endl;
        //         return;
        //     }

        //     int index = front[qi];
        //     front[qi] = -1;
        //     while(index != rear[qi]){

        //     }
        // }

        ~KQueue(){
            delete [] arr;
            delete [] front;
            delete [] rear;
            delete [] next;
        }
};

int main()
{
    KQueue* q = new KQueue(10,3);
    q->push(1,1);
    q->push(2,2);
    q->push(3,3);
    q->print();

    return 0;
}