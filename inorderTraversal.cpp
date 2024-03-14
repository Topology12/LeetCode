#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<int> travelTree(TreeNode *&root, vector<int> &nums);
vector<int> inorderTraversal(TreeNode *&root);
void createTreeNode(TreeNode *&root);
TreeNode *createNode(int val);
void insertNode(TreeNode *&root, int val);
void displayTree(TreeNode *root);
int main()
{
    TreeNode *root = NULL;
    createTreeNode(root);
    vector<int> result = inorderTraversal(root);
    return 0;
}

vector<int> inorderTraversal(TreeNode *&root)
{
    vector<int> result;
    result = travelTree(root, result);
    return result;
}
vector<int> travelTree(TreeNode *&root, vector<int> &nums)
{
    if (!root)
        return nums;
    if (root->left == NULL && root->right == NULL)
    {
        nums.push_back(root->val);
        return nums;
    }
    nums = travelTree(root->left, nums);
    nums.push_back(root->val);
    nums = travelTree(root->right, nums);
    return nums;
}
void createTreeNode(TreeNode *&root)
{
    int n;
    cout << "Nhap so nut cua cay = ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int value;
        cout << "Nhap value cua nut = ";
        cin >> value;
        insertNode(root, value);
    }
}
void insertNode(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = createNode(val);
        return;
    }
    if (root->val < val)
        insertNode(root->left, val);
    else
        insertNode(root->right, val);
}
TreeNode *createNode(int val)
{
    TreeNode *temp = new TreeNode();
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void displayTree(TreeNode* root){
    if(root == NULL)
        return; 
    displayTree(root->left); 
    root->val;
    displayTree(root->right);
}