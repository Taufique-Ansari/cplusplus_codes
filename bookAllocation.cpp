#include <iostream>
#include <numeric>
using namespace std;

bool possibleSol(int A[], int N, int M, int sol){
    int pageSum = 0;
    int c = 1;
    for(int i = 0; i < N; i++){
        if(A[i] > sol){
            return false;
        }
        if(pageSum + A[i] > sol){
            pageSum = A[i];
            c++;
            if(c > M) return false;
        }else{
            pageSum += A[i];
        }
    }
    return true;
}

int bookAlloc(int A[],int N, int M){
    if(N<M) return -1;
    int s = 0;
    int e = accumulate(A,A+N,0);
    int ans = -1;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(possibleSol(A,N,M,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

int main()
{
    //N is the no. of books which is allocated to students in such a way that the each student must have at least one book,the goal is to find the permutation where the student with the most pages allocated to him gets the minimum number of pages, out of all possible permutations.
    int A[] = {12,34,67,90};
    int N = 4;
    int M = 2;
    cout<<bookAlloc(A,N,M)<<endl;

    return 0;
}