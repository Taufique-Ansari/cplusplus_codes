#include <iostream>
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
    cout<<"Enter data:";
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

vector<int> morrisTraversal(node* root){
    vector<int> ans;
    node* curr = root;
    while(curr){
        if(curr->left == nullptr){
            ans.push_back(curr->data);
            curr = curr->right;
        }else{
            node* pred = curr->left;
            while(pred->right && pred->right != curr){
                pred = pred->right;
            }
            if(pred->right == nullptr){
                pred->right = curr;
                curr = curr->left;
            }else{
                pred->right = nullptr;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    node* root = NULL;
    root = makeTree(root);

    vector<int> ans = morrisTraversal(root);
    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}