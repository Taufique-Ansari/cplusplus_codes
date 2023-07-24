#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class node{
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

node* makeTree(node* root){
    cout<<"Enter data: ";
    int data;cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for left of "<<data<<endl;
    root->left = makeTree(root->left);
    cout<<"Enter data for the right of "<<data<<endl;
    root->right = makeTree(root->right);

    return root;
}

vector<int> verticalTraversal(node* root){
    map<int,map<int,vector<int> > > nodes;
    queue<pair<node*,pair<int,int> > > q;
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

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

vector<int> topView(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int,int> topNode;
    queue<pair<node*,int> > q;

    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    for(auto i : topNode){
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    node* root = NULL;
    root = makeTree(root);
    // vector<int> a = verticalTraversal(root);
    // for(int i = 0; i < a.size(); i++){
    //     cout<<a[i]<<" ";
    // }
    vector<int> b = topView(root);
    for(int i = 0; i < b.size(); i++){
        cout<<b[i]<<" ";
    }

    return 0;
}