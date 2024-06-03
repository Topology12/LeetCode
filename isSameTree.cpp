#include <iostream>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p && q)
    {
        if (p->val == q->val)
        {
            if (p->left == NULL && q->left == NULL)
                return isSameTree(p->right, q->right);
            if (p->right == NULL && q->right == NULL)
                return isSameTree(p->left, q->left);
            return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
        }
        return false;
    }
    return false;
}

int main()
{
    return 0;
}