struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isSubtreeAtRoot(TreeNode *root1, TreeNode *root2)
	{
		if (root2 == nullptr)
			return true;
		if (root1 == nullptr)
			return false;
		if (root1->val != root2->val)
			return false;
		return isSubtreeAtRoot(root1->left, root2->left) && isSubtreeAtRoot(root1->right, root2->right);
	}

	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		if (isSubtreeAtRoot(pRoot1, pRoot2))
			return true;
		return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
};