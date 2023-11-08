#include <iostream>

using namespace std;

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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *result = reverseList(head->next);
        head -> next -> next = head;
        head -> next = nullptr;
        return result;
    }
};

/*
head = 1 2 3 4, 
head = 2 3 4,  rev = 4 3 
head = 3 4,    rev = 4, 
return 4


*/

int main()
{

    Solution *sol = new Solution();
    ListNode *head = new ListNode(4, nullptr);
    head = new ListNode(3, head);
    head = new ListNode(2, head);
    head = new ListNode(1, head);

    sol->reverseList(head);
}