#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node {
public:
  int data;
  node *left;
  node *right;

  node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

node *makeTree(node *root) {
  cout << "Enter data: " << endl;
  int data;
  cin >> data;
  root = new node(data);

  if (data == -1) {
    return NULL;
  }

  root->left = makeTree(root->left);
  root->right = makeTree(root->right);

  return root;
}

void solve(node *root, vector<int> &ans, int level) {
  if (root == NULL) {
    return;
  }
  if (level == ans.size()) {
    ans.push_back(root->data);
  }

  if (root->left) {
    solve(root->left, ans, level + 1);
  }
  if (root->right) {
    solve(root->right, ans, level + 1);
  }
}

vector<int> leftView(node *root) {
  vector<int> ans;
  solve(root, ans, 0);

  return ans;
}

int main() {
  node *root = NULL;
  root = makeTree(root);

  vector<int> a = leftView(root);
  for (auto i : a) {
    cout << i << " ";
  }
}