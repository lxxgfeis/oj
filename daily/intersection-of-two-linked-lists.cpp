/* 160
    https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        //

        ListNode *x = headA;
        ListNode *y = headB;

        while (x != nullptr && y != nullptr)
        {
            x = x->next;
            y = y->next;
        }
        ListNode *l, *s;
        if (x == nullptr)
        {
            s = headA;
            l = headB;
        }
        else
        {
            s = headB;
            l = headA;
        }
        x = (x == nullptr) ? y : x;
        while (x != nullptr)
        {
            x = x->next;
            l = l->next;
        }
        for (;;)
        {
            if(l==s) {
                return l;
            }
            l = l->next;
            s = s->next;
            if (l==nullptr || s==nullptr) {
                return nullptr;
            }
        }
    }
};