#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
struct Tree
{
    TreeNode *root;
};

void createTree(Tree &tree);
void initTree(Tree &tree);
TreeNode *createNode(int val);
void insertNodeLeft(TreeNode *&, int val);
void insertNodeRight(TreeNode *&, int val);
void displayTree(TreeNode *&node);
bool leftAndRight(TreeNode *&lnode, TreeNode *&rnode);
bool isMetricTree(Tree &tree);

int main()
{
    Tree mainTree;
    createTree(mainTree);
    initTree(mainTree);
    displayTree(mainTree.root);
    bool result = isMetricTree(mainTree);
    cout << result;
    return 0;
}
TreeNode *createNode(int val)
{
    TreeNode *node = new TreeNode();
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void createTree(Tree &tree)
{
    tree.root = NULL;
}
void insertNodeLeft(TreeNode *&root, int val)
{
    if (root == NULL)
        root = createNode(val);
    else
    {
        if (root->val < val)
            insertNodeLeft(root->right, val);
        else
            insertNodeLeft(root->left, val);
    }
}
void insertNodeRight(TreeNode *&root, int val)
{
    if (root == NULL)
        root = createNode(val);
    else
    {
        if (root->val > val)
            insertNodeRight(root->right, val);
        else
            insertNodeRight(root->left, val);
    }
}
void initTree(Tree &tree)
{
    int val;
    cout << "Nhap gia tri nut goc = ";
    cin >> val;
    tree.root = createNode(val);
    int n;
    cout << "Nhap so nut muon tao o moi nhanh = ";
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int value;
        cout << "Nhap gia tri nut muon them vao = ";
        do
        {
            cin >> value;
        } while (value < val);
        insertNodeLeft(tree.root->left, value);
        insertNodeRight(tree.root->right, value);
        i++;
    }
}
void displayTree(TreeNode *&node)
{
    if (node == NULL)
        return;
    cout << node->val << " ";
    displayTree(node->right);
    displayTree(node->left);
}
bool leftAndRight(TreeNode *&lnode, TreeNode *&rnode)
{
    if (lnode == NULL || rnode == NULL)
        return true;
    if (lnode == NULL || rnode == NULL)
        return false;
    if (lnode->val == rnode->val)
        return (leftAndRight(lnode->left, rnode->right) && leftAndRight(lnode->right, rnode->left));
}
bool isMetricTree(Tree &tree)
{
    if (tree.root == NULL)
        return true;
    return leftAndRight(tree.root->left, tree.root->right);
}
