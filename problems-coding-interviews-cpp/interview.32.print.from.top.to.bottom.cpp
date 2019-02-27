#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root)
	{
		vector<int> v;
		if (root != nullptr)
		{
			queue<TreeNode *> q;
			q.push(root);
			while (!q.empty())
			{
				TreeNode *node = q.front();
				q.pop();
				if (node->left != nullptr)
					q.push(node->left);
				if (node->right != nullptr)
					q.push(node->right);
				v.push_back(node->val);
			}
		}
		return v;
	}
};