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
class Solution {
    ListNode* reverse(ListNode* start, ListNode* end)
    {
        ListNode* curr = start, *prev = NULL, *nxt = NULL, *last = end->next;
        while(curr != last)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* insert_end(ListNode * ans, ListNode* n)
    {
        
        ans->next = n;
        while(ans->next != NULL)
        {
            ans = ans->next;
        }
        return ans;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * ans, *res, *end = head, *start = end;
        ans = new ListNode(0);
        res = ans;
        int c{1};
        while(end != NULL)
        {
            if(c % k != 0)
            {
                end = end->next;
                ++c;
            } 
            else
            {
                auto temp = end->next;
                auto n = reverse(start, end);
                ans = insert_end(ans, n);
                start = temp;
                end = start;
                ++c;
            }
        }
        while(start != NULL)
        {
            ans->next = start;
            start = start->next;
            ans = ans->next;
        }
        return res->next;
    }
};