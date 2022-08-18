#include <iostream>
#include <vector>
using namespace std;

bool myCompare(const pair<int,int> &p, const pair<int,int> &p1){
    return (p.second < p1.second);
}

int main()
{
    vector< pair<int,int> > vect;
    int arr[] = {1,2,4,3,5};
    int arr1[] = {5,4,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++){
        vect.push_back(make_pair(arr[i],arr1[i]));
    }
    cout<<"This is before sorting\n"<<endl;
    for(int i = 0; i < n; i++){
        cout<<vect[i].first<<" "<<vect[i].second<<endl;
    }cout<<endl;

    cout<<"This is after sorting w.r.t first vect\n"<<endl;
    sort(vect.begin(),vect.end());
    for(int i = 0; i < n; i++){
        cout<<vect[i].first<<" "<<vect[i].second<<endl;
    }

    sort(vect.begin(),vect.end(),myCompare);
    cout<<"This is after sorting w.r.t second vect\n"<<endl;
    for(int i = 0; i < n; i++){
        cout<<vect[i].first<<" "<<vect[i].second<<endl;
    }
}