#include <iostream>
#include <vector>

using namespace std;

#define ROW 4
#define COL 5

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for(int i = 0; i <v.size(); i++){
        cout<<v[i]<<endl;
    }//1 2 3

    vector<int>::iterator it;
    for(it= v.begin();it!= v.end();it++){
        cout<<*it<<endl;
    }

    for(auto element:v){
        cout<<element<<endl;
    }

    pair<int, char> p;
    p.first = 3;
    p.second = 'T';
    cout<<p<<endl;

    // vector<vector<int> > vec; //2d vector
    // int num = 10;

    // for(int i = 0; i < ROW; i++){
    //     vector<int> v1;
    //     for(int j = 0;j < COL; j++){
    //         v1.push_back(num);
    //         num += 5;
    //     }
    //     vec.push_back(v1);
    // }

    // for(int i = 0; i < vec.size(); i++){
    //     for(int j = 0; j < vec[i].size(); j++){
    //         cout<<vec[i][j]<<" ";
    //     }cout<<endl;
    // }
    return 0;
}