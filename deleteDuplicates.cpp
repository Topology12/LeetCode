#include <iostream>
#include <set>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val, ListNode *add)
    {
        this->val = val;
        this->next = add;
    }
} ListNode;

ListNode *deleteDuplicates(ListNode *head)
{
    set<int> checkmap;
    ListNode *prev = head;
    ListNode *curr = head;
    while (curr)
    {
        if (checkmap.find(curr->val) == checkmap.end())
            checkmap.insert(curr->val);
        else
        {
            ListNode *temp = curr->next;
            delete curr;
            curr = temp;
            prev->next = curr;
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}
ListNode *deleteDuplicatesVersionTwo(ListNode *head)
{
    ListNode *curr = head;
        while(curr && curr->next)
        {
            if(curr->val == curr->next->val)
            {
                ListNode * temp = curr->next->next;
                delete curr->next; 
                curr->next = temp; 
            }
            else{
                curr = curr->next;
            }
        }
        return head;
}
int main()
{
    ListNode *head = NULL;
    ListNode *node = new ListNode(1, NULL);
    head = node;
    node = new ListNode(1, NULL);
    head->next = node;
    node = new ListNode(2, NULL);
    head->next->next = node;
    head = deleteDuplicates(head);
    while (head)
    {
        cout << head->val << " ";
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
    delete node;
    return 0;
}