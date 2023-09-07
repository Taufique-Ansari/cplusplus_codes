#include <iostream>
#include <queue>
using namespace std;

//Base of making a Tree i.e Node/Root
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(node* root, int level);
int treeHeight(node* root);

//Making a Tree
node* makeTree(node *root)
{
    cout << "Enter data: ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter value to be put on left of " << data << endl;
    root->left = makeTree(root->left);
    cout << "Enter value to be put on right of " << data << endl;
    root->right = makeTree(root->right);

    return root;
}

//Level Order Tranversal is a method of printing the data in binary tree according to thier level
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void printLevelOrder(node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout<<root->data<<" ";
        return;
    }
    else{
        printLevelOrder(root->left,level-1);
        printLevelOrder(root->right,level-1);
    }
}

void reverLevelOrder(node* root){
    int h = treeHeight(root);

    for(int i = h; i >= 1; i--){
        printLevelOrder(root,i);
    }
}



//Inorder in this output is in between L and R
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);       // L
    cout << root->data << " "; // N
    inorder(root->right);      // R
}

//Preorder means ouput is before L and R
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " "; // N
    preorder(root->left);      // L
    preorder(root->right);     // R
}

//Postorder means output or condition for output is at the last i.e after L and R
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);     // L
    postorder(root->right);    // R
    cout << root->data << " "; // N
}

//Making a binary tree using level order method
void buildFromLevelOrder(node *&root)
{
    queue<node *> q;

    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int treeHeight(node* root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(treeHeight(root->left),treeHeight(root->right));
}

int main()
{
    node *root = NULL;
    // buildFromLevelOrder(root);
    // levelOrderTraversal(root);
    root = makeTree(root);

    // cout << "Level order traversal is " << endl;
    // levelOrderTraversal(root);

    reverLevelOrder(root);

    // cout << "Inorder traversal is ";
    // inorder(root);
    // cout << endl;

    // cout << "Preorder tranersal is ";
    // preorder(root);
    // cout << endl;

    // cout << "Postorder tranersal is ";
    // postorder(root);

    cout<<"Height of tree is: "<<treeHeight(root);
    // 3 2 1 -1 -1 -1 5 4 -1 -1 6 -1 7 -1 -1
    //                3
    //               / \
    //              2   5
    //             /   / \
    //            1   4   6
    //                     \
    //                      7

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    return -1;
}