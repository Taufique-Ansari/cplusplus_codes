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

vector <int> bottomView(node *root) {
    map<int,int> bottomNodes;
    queue<pair<node*,int> > q;
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();
        
        node* frontNode = temp.first;
        int hd = temp.second;
        
        bottomNodes[hd] = frontNode->data;
        
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    
    for(auto i : bottomNodes){
        ans.push_back(i.second);
    }
    
    return ans;
    
}

int main(){
  node* root = NULL;
  root = makeTree(root);

  vector<int> a = bottomView(root);
  for(auto i : a){
    cout<<i<<" ";
  }

  //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  return 0;
}