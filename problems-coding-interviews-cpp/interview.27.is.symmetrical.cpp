struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isSymmetrical(TreeNode *root1, TreeNode *root2)
	{
		if (root1 == nullptr && root2 == nullptr)
			return true;
		if (root1 == nullptr || root2 == nullptr)
			return false;
		if (root1->val != root2->val)
			return false;
		return isSymmetrical(root1->left, root2->right) && isSymmetrical(root1->right, root2->left);
	}

	bool isSymmetrical(TreeNode* root)
	{
		return isSymmetrical(root, root);
	}
};