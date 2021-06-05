/* 203
    https://leetcode-cn.com/problems/remove-linked-list-elements/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head != nullptr)
        {
            if (head->val != val)
            {
                break;
            }
            head = head->next;
        }
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *prev = head;
        ListNode *curr = head->next;
        while (curr != nullptr)
        {
            if (curr->val == val)
            {
                prev->next = curr->next;
            }
            else
            {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return head;
    }
};