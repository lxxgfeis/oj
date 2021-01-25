/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i < b; i++)
class Solution {
private:
    unordered_map<int, int> myMap; 
    vector<int> myPre;
private:
    // root是根节点在preorder中的下标，left和right是子树在inorder中的起始和终止下标
    TreeNode* build(int root, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int rootVal = myPre[root];
        TreeNode* ans = new TreeNode(rootVal);
        // 根据事先构造好的hash table，找到根节点在inorder的下标
        int rootIdx = myMap[rootVal];
        ans->left  = build(root+1, left, rootIdx-1);
        ans->right = build(root+rootIdx-left+1, rootIdx+1, right);
        return ans;
    }
public:
    // 剑指 Offer 07. 重建二叉树
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }
        REP(i, 0, inorder.size()) {
            myMap.insert(MP(inorder[i], i));
        }
        REP(i, 0, preorder.size()) {
            myPre.PB(preorder[i]);
        }
        return build(0, 0, inorder.size()-1);
    }
};
