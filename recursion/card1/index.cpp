#include <iostream>
#include <forward_list>

using namespace std;

void reverse(const string &s, int i = 0)
{
    if (i < s.length())
    {
        reverse(s, i + 1);
    }
    cout << s[i];
}

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapAdjNodes(ListNode *list)
{
    if (list->next == nullptr)
    {
        return list;
    }
    list = swapAdjNodes(list->next);
    cout << list->val;
}

int main()
{
    // reverse("KcihtraK");
    // cout << endl;

    ListNode *list = new ListNode(4, nullptr);
    list = new ListNode(3, list);
    list = new ListNode(2, list);
    list = new ListNode(1, list);

    swapAdjNodes(list);
    cout << endl;
}