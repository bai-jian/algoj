struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	void Mirror(TreeNode *root)
	{
		if (root != nullptr)
		{
			Mirror(root->left);
			TreeNode *left = root->left;
			Mirror(root->right);
			TreeNode *right = root->right;
			root->left = right;
			root->right = left;
		}
	}
};