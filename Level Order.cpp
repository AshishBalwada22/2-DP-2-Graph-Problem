/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> res;
    vector<int> subset;
    res.clear();
    subset.clear();
    if(A==NULL) return res;
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    while(!q.empty())
    {
        TreeNode*temp=q.front();
        if(temp!=NULL)
        subset.push_back(temp->val);
        q.pop();
        if(temp==NULL)
        {
            res.push_back(subset);
            subset.clear();
            if(!q.empty())
            q.push(NULL);
        }
        else
        {
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
        }
    }
    return res;
}

