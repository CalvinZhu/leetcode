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
ListNode *sortList(ListNode *head) {  
        // IMPORTANT: Please reset any member data you declared, as  
        // the same Solution instance will be reused for each test case.  
    if(!head)  
        return NULL;  
    int k=0;  
    ListNode *p=head;  
    while(p)  
    {  
        k++;  
        p=p->next;  
    }  
    if(k==1)  
        return head;  
    int l=k/2;    //计算结点个数，将链表分开。  
    p=head;  
    ListNode *q=head,*t=NULL;  
    for(int i=0;i<l && q ;i++)  
    {  
        if(i==l-1)  
            t=q;  
        q=q->next;  
    }  
    if(t)  
        t->next=NULL;//将链表分开。  
    p=sortList(p);//分别对两段排序  
    q=sortList(q);  
    ListNode *hd=NULL,*pp=NULL;  
    while(p&&q)//合并  
    {  
        if(p->val<=q->val)  
        {  
            if(!hd)              
               pp=hd=p;             
            else 
            {  
                pp->next=p;  
                pp=p;  
            }  
            p=p->next;  
        }  
        else 
        {  
            if(!hd)             
                hd=pp=q;             
            else 
            {  
                pp->next=q;  
                pp=q;  
            }  
            q=q->next;  
        }  
    }  
    if(p)  
        pp->next=p;  
    if(q)  
        pp->next=q;  
    return hd;  
}  
};
