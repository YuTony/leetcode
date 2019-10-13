//https://leetcode.com/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* l = root;
        int n = 0;
        while (l != NULL) {
            n++;
            l = l->next;
        }
        vector<ListNode*> ans(k);
        int kol = n / k, ost = n % k;
        for (int i = 0; i < k; i++) {
            if (root != NULL) {
                ans[i] = NULL;
                ListNode *prev = NULL;
                for (int j = 0; j < kol + (ost > 0 ? 1 : 0); j++) {
                    ListNode *node = new ListNode(root->val);
                    root = root->next;
                    if (prev)
                        prev->next = node;
                    if (!ans[i])
                        ans[i] = node;
                    prev = node;
                }
                ost--;
            }
        }
        return ans;
    }
};
