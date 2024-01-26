#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *result = new ListNode();
    ListNode *T = result;
    int temp = 0;
    while (l1 != NULL && l2 != NULL)
    {
        int sum = l1->val + l2->val + temp;
        temp = sum / 10;
        T->next = new ListNode(sum % 10);
        l1 = l1->next;
        l2 = l2->next;
        T = T->next;
    }
    while (l1 != NULL)
    {
        int sum = l1->val + temp;
        temp = sum / 10;
        T->next = new ListNode(sum % 10);
        l1 = l1->next;
        T = T->next;
    }
    while (l2 != NULL)
    {
        int sum = l2->val + temp;
        temp = sum / 10;
        T->next = new ListNode(sum % 10);
        l2 = l2->next;
        T = T->next;
    }
    if (temp != 0)
    {
        T->next = new ListNode(temp);
    }
    return result = result->next;
}

void cinNode(ListNode *&T)
{
    int n;
    cout << "Nhap so nut:  ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        if (T == NULL)
            T = new ListNode(value);
        else
            T->next = new ListNode(value);
        T = T->next;
    }
}
int main()
{
    ListNode *l1;
    cinNode(l1);
    ListNode *l2;
    cinNode(l2);
    ListNode *result = addTwoNumbers(l1, l2);
    while (result != NULL)
    {
        cout << result->val;
        result = result->next;
    }
    free(l1);
    free(l2);
    return 0;
}