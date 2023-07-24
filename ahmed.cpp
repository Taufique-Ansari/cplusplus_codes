#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> arr , int target){
  int s = 0;
  int e = arr.size()-1;
  int mid = s + (e-s)/2;
  while(s<=e){   
    if (target == arr[mid]){   
         return mid;
    }
    if (mid - 1 >= 0 && arr[mid-1] == target){
      return mid - 1;
    }
    if (mid + 1 < arr.size() && arr[mid+1] == target){
      return mid + 1;
    }
    else if (target > arr[mid]){
      s = mid + 2;   // mid +1 isiliye nhi kia kyuki woh element already checked hei
    }
    else{
      e = mid - 2;    //already checked hei
    }
    mid = s + (e-s)/2;
  }
  return -1;

}
int main(){
   vector<int> arr = {10,30,20,50,40,60,70};
   int target = 10;
   int ans = binarySearch(arr , target);
   cout << "index of " << target << " is " << ans << endl;
   return 0;
}