#include <iostream>
#include <queue>
#include <unordered_map>
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

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int findPosition(int inorder[],int size, int ele){
    for(int i = 0; i < size; i++){
        if(inorder[i] == ele){
            return i;
        }
    }
    return -1;
}

node* buildFromInorderPreorder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd, unordered_map<int,int> &mapping){
    if(preIndex > size || inorderStart > inorderEnd){
        return NULL;
    }

    int ele = preorder[preIndex++];
    node* n = new node(ele);
    int pos = mapping[ele];

    n->left = buildFromInorderPreorder(inorder,preorder,size,preIndex,inorderStart,pos-1,mapping);
    n->right = buildFromInorderPreorder(inorder,preorder,size,preIndex,pos+1,inorderEnd,mapping);

    return n;
}

int main()
{
    int inorder[] = {40,20,50,10,60,30,70};
    int preorder[] = {10,20,40,50,30,60,70};
    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size-1;
    unordered_map<int,int> mapping;
    for(int i = 0; i < size; i++){
        mapping[inorder[i]] = i;
    }
    node* root = buildFromInorderPreorder(inorder,preorder,size,preIndex,inorderStart,inorderEnd,mapping);
    levelOrderTraversal(root);

    return 0;
}