#include <iostream>
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
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter Data to the left of "<<data<<endl;
    root->left = makeTree(root->left);
    cout<<"Enter Data to the right of "<<data<<endl;
    root->right = makeTree(root->right);

    return root;
}

void leftTraversal(node* root,vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    ans.push_back(root->data);
    if(root->left){
        leftTraversal(root->left,ans);
    }
    else{
        leftTraversal(root->right,ans);
    }

}

void leafTraversal(node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    leafTraversal(root->left,ans);
    leafTraversal(root->right,ans);
}

void rightTraversal(node* root, vector<int> &ans){
    if(root == NULL || root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right){
        rightTraversal(root->right,ans);
    }
    else{
        rightTraversal(root->left,ans);
    }

    ans.push_back(root->data);
}

vector<int> boundary(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);
    //left
    leftTraversal(root->left, ans);

    //leaf
    leafTraversal(root->left,ans);
    leafTraversal(root->right,ans);

    //rightTraversal
    rightTraversal(root->right,ans);

    return ans;
}

int main()
{
    node* root = NULL;
    root = makeTree(root);
    vector<int> a = boundary(root);
    cout<<endl;
    for(int i = 0; i < a.size(); i++){
        cout<<a[i]<<" ";
    }  

    return 0;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
}