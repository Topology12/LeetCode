#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

void createNodeFirst(TreeNode *&root);
TreeNode *createTreeNode(int val);
void insertNode(TreeNode *&root, int val);
void createBinaryTree(TreeNode *&root);
int maxDepth(TreeNode *root);

int main()
{
    TreeNode *root;
    createNodeFirst(root);
    createBinaryTree(root);
    if (root)
        cout << "Not NULL";
    cout << maxDepth(root);
    return 0;
}

void createNodeFirst(TreeNode *&root)
{
    root = NULL;
}

TreeNode *createTreeNode(int val)
{
    TreeNode *temp = new TreeNode();
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insertNode(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = createTreeNode(val);
        return;
    }
    if (root->val < val)
        insertNode(root->left, val);
    else
        insertNode(root->right, val);
}

void createBinaryTree(TreeNode *&root)
{
    int n;
    cout << "Nhap so nut muon them vao cay n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Nhap gia tri cua nut value = ";
        cin >> value;
        insertNode(root, value);
    }
}
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return maxDepth(root->left) > maxDepth(root->right) ? 1 + maxDepth(root->left) : 1 + maxDepth(root->right);
}
