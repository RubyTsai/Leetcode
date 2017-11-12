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
        vector<ListNode*> c;
        ListNode* node = root;
        while (node) {
            c.emplace_back(node);
            node = node->next;
        }
        int size = c.size()/k;
        int extra = c.size()%k;
        
        vector<ListNode*> ans(k);
        if (root) {
            for (int i = 0, idx = 0; i < k && idx < c.size(); i++) {
                ans[i] = c[idx];
                int last = idx + size - 1;
                if (i < extra) last++;
                c[last]->next = NULL;
                idx = last+1;
            }
        }
        return ans;
    }
};
