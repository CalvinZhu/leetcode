/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
 //http://www.2cto.com/kf/201401/276086.html
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *tHead = head;
        RandomListNode *next = NULL;
        while(tHead)
        {
            next = tHead->next;
            RandomListNode *node = new RandomListNode(tHead->label);
            node->next = tHead->next;
            //node->random = tHead->random;
            tHead->next = node;
            tHead= next;
        }
        tHead = head;
        while(tHead)
        {
            if(tHead->random) tHead->next->random = tHead->random->next;
            tHead = tHead->next->next;
        }
        RandomListNode *retHead = NULL;
        RandomListNode *tRet = NULL;
         
        tHead = head;
        RandomListNode *next2 = NULL;
        while(tHead)
        {
            if(retHead == NULL)
            {  
                next2 = tHead->next->next;
                retHead = tHead->next;
                tRet = retHead;
                tHead->next = next2;
                tHead = next2;
            }
            else
            {
                next2 = tHead->next->next;
                tRet->next = tHead->next;
                tHead->next = next2;
                tHead = next2;
                tRet = tRet->next;
            }
 
        }
        return retHead;
    }
};
