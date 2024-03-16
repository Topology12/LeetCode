#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<int> travelTree(TreeNode *root, vector<int> &nums);
vector<int> inorderTraversal(TreeNode *root);
vector<int> inorderTraversalTwo(TreeNode *root);
TreeNode *createNode(int val);
void createTree(TreeNode *&root);
void insertNode(TreeNode *&root, int val);
void createTreeNode(TreeNode *&root);
void displayTree(TreeNode *root);

int main()
{
    TreeNode *root;
    createTree(root);
    createTreeNode(root);
    if (!root)
        cout << "error";
    displayTree(root);
    vector<int> result = inorderTraversal(root);
    vector<int> result2 = inorderTraversalTwo(root);
    for (int i = 0; i < result2.size(); i++)
        cout << result2[i];
    return 0;
}

void createTree(TreeNode *&root)
{
    root = NULL;
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    result = travelTree(root, result);
    return result;
}
vector<int> travelTree(TreeNode *root, vector<int> &nums)
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
TreeNode *createNode(int val)
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
        root = createNode(val);
        return;
    }
    if (root->val < val)
        insertNode(root->right, val);
    else
        insertNode(root->left, val);
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
void displayTree(TreeNode *root)
{
    if (root == NULL)
        return;
    displayTree(root->left);
    root->val;
    displayTree(root->right);
}
vector<int> inorderTraversalTwo(TreeNode *root)
{
    stack<TreeNode *> temp;
    vector<int> result;
    TreeNode *curr = root;
    while (curr || temp.empty())
    {

        while (!curr)
        {
            temp.push(root);
            root = root->left;
        }
        curr = temp.top();
        temp.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    return result;
}