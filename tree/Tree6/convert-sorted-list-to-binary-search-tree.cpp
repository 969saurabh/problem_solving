//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
class Solution {
public:
TreeNode* constructBST(ListNode* start,ListNode* end)
{
    if(start==end)
    return NULL;
    ListNode *t1=start,*t2=start;
    while(t2!=end&&t2->next!=end)
    {
        t1=t1->next;
        t2=t2->next->next;
    }
    TreeNode* root=new TreeNode(t1->val);
    root->left=constructBST(start,t1);
    root->right=constructBST(t1->next,end);
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        return constructBST(head,NULL);
    }
};