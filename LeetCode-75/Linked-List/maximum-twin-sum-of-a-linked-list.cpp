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
public:
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            temp = temp->next;
            n++;
        }
        temp = head;
        for(int i=0;i<n/2;i++){
            temp = temp->next;
        }
        ListNode* prev = nullptr;
        while(temp != nullptr){
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        ListNode* temp2 = prev;
        int ans = INT_MIN;
        temp = head;
        while(temp2 != nullptr){
            ans = max(ans, temp->val + temp2->val);
            temp = temp->next;
            temp2 = temp2->next;
        }
        return ans;
    }
};
