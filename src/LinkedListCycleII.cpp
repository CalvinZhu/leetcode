/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //http://www.cnblogs.com/easonliu/p/3650677.html
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        while (slow != NULL && fast != NULL) {
            if (slow->next != NULL) {
                slow = slow->next;
            } else {
                return NULL;
            }
            if (fast->next != NULL) {
                fast = fast->next;
            } else {
                return NULL;
            }
            if (fast->next != NULL) {
                fast = fast->next;
            } else {
                return NULL;
            }
            if (slow == fast) {
                break;
            }
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
