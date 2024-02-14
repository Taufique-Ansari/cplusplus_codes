#include <iostream>
#include <queue>
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

node* buildFromInorderPostorder(int inorder[], int postorder[], int size, int &postIndex, int inorderStart, int inorderEnd,unordered_map<int,int> &mapping){
    if(postIndex < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    int ele = postorder[postIndex--];
    node* n = new node(ele);
    int pos = mapping[ele];

    n->right = buildFromInorderPostorder(inorder,postorder,size,postIndex,pos+1,inorderEnd,mapping);
    n->left = buildFromInorderPostorder(inorder,postorder,size,postIndex,inorderStart,pos-1,mapping);

    return n;
}

int main()
{
    int inorder[] = {40,20,50,10,60,30,70};
    int postorder[] = {40,50,20,60,70,30,10};
    int size = 7;
    int postIndex = size-1;
    int inorderStart = 0;
    int inorderEnd = size-1;
    unordered_map<int,int> mapping;
    for(int i = 0; i < size; i++){
        mapping[inorder[i]] = i;
    }
    node* root = buildFromInorderPostorder(inorder,postorder,size,postIndex,inorderStart,inorderEnd,mapping);
    levelOrderTraversal(root);

    return 0;
}