/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //http://blog.csdn.net/doc_sgl/article/details/13614853
class Solution {  
public:  
    bool hasCycle(ListNode *head) {  
        // IMPORTANT: Please reset any member data you declared, as  
        // the same Solution instance will be reused for each test case.  
        ListNode* pfast = head;  
        ListNode* pslow = head;  
        do{  
            if(pfast!=NULL)  
                pfast=pfast->next;  
            if(pfast!=NULL)  
                pfast=pfast->next;  
            if(pfast==NULL)  
                return false;  
            pslow = pslow->next;  
        }while(pfast != pslow);  
        return true;  
    }  
};  
