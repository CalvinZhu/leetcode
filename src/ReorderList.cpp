/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //http://blog.csdn.net/magisu/article/details/14161185
class Solution {  
public:  
    void reorderList(ListNode *head) {  
        if (head == nullptr)  
            return;  
          
        vector<ListNode*> nodes;  
        ListNode* iter = head;  
        while(iter != nullptr)  
        {  
            nodes.push_back(iter);  
            iter = iter->next;  
        }  
          
        int LEN = nodes.size();  
        int left = 0;  
        int right = LEN -1;  
        while(left < right)  
        {  
            nodes[left]->next = nodes[right];  
            nodes[right--]->next = nodes[++left];  
        }  
        nodes[left]->next = nullptr;  
    }  
};  
