#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

class node {
  public:
    int data;
    node* left;
    node* right;

    node(int val){
      data = val;
      left = NULL;
      right = NULL;
    }
};

node*  makeTree(node* root){
  cout<<"Enter data: "<<endl;
  int data;
  cin>>data;
  root = new node(data);

  if(data == -1){
    return NULL;
  }

  root->left = makeTree(root->left);
  root->right = makeTree(root->right);

  return root;
}

vector<int> vertical(node* root){
  vector<int> ans;
  if(root == NULL){
    return ans;
  }

  map<int,map<int,vector<int> > > nodes;
  queue<pair<node*, pair<int,int> > > q;

  q.push(make_pair(root,make_pair(0,0)));
  while(!q.empty()){
    pair<node*,pair<int,int> > temp = q.front();
    q.pop();

    node* frontNode = temp.first;
    int hd = temp.second.first;
    int lvl = temp.second.second;

    nodes[hd][lvl].push_back(frontNode->data);

    if(frontNode->left){
      q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
    }
    if(frontNode->right){
      q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
    }
  }

  for(auto i: nodes){
    for(auto j : i.second){
      for(auto k : j.second){
        ans.push_back(k);
      }
    }
  }

  return ans;
}

int main(){
  node* root = NULL;
  root = makeTree(root);

  vector<int> a = vertical(root);
  for(auto i : a){
    cout<<i<<" ";
  }

  //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  return 0;
}