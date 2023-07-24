#include<iostream>
using namespace std;
int findsqrt (int n){
  int s = 0;
  int e = n;
  int mid = s + (e-s) / 2;
  int target = n;
  int ans = -1; //for storing the mid in right search

  while (s <= e){
    if (mid * mid == target){
      return mid;
    }
    if (mid * mid > target){
     e = mid -1;
    }
    else {
      ans = mid ; //storing the answer
      s = mid + 1;
    }
    mid = s + (e-s) / 2;
  }
  return ans;
}
int main(){
     int n;
     cout << "Enter the number" << endl;
     cin >> n;
     int ans = findsqrt (n);
     cout << "The square root is " << ans;
}