/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        // 不难，细心即可
        if (head == NULL || head->next == NULL) {
            return head;
        }
        auto next = head->next;
        head->next = NULL; // 关键步骤
        for(;;) {
            auto tmp = next->next;
            next->next = head;
            head = next;
            if (tmp == NULL) {
                break;
            }
            next = tmp;
        }
        return next;
    }

    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        auto p = reverse(head);
        for(;;) {
            if (p == NULL) {
                break;
            }
            ans.push_back(p->val);
            p = p->next;
        }
        return ans;
    }
};
