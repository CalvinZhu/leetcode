/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode insertionSortList(ListNode head) {
               if(head == null || head.next == null)  
            return head;  
        ListNode resHead = null;  
        ListNode resTail = null;  
        while( head != null){  
            ListNode curr = head;  
            head = head.next;  
            //if it's the first node, we can set resHead and resTail  
            if( resHead == null){  
                resHead = curr;  
                resTail = curr;  
                resTail.next = null;  
            // if the current node is smaller than head, we insert before the resHead  
            } else if(curr.val <= resHead.val){  
                curr.next = resHead;  
                resHead = curr;  
            // if the current node is larger than tail, we insert after the resTail  
            } else if(curr.val >= resTail.val){  
                resTail.next = curr;  
                resTail = curr;  
                resTail.next = null;  
            // otherwise, when the current node's value is in the middle,   
            // we should go through the result list to find the right insertion position  
            } else {  
                ListNode findPos = resHead;  
                while(curr.val > findPos.next.val){  
                    findPos = findPos.next;  
                }  
                curr.next = findPos.next;  
                findPos.next = curr;    
            }  
        }  
        return resHead;
    }
}
