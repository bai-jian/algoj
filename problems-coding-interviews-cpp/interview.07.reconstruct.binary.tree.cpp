#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		if (pre.size() == 0)
			return nullptr;

		int val = pre[0];
		TreeNode* node = new TreeNode(val);
		auto iter = find(vin.cbegin(), vin.cend(), val);
		node->left = reConstructBinaryTree(
			vector<int>(pre.cbegin() + 1, pre.cbegin() + 1 + (iter - vin.cbegin())),
			vector<int>(vin.cbegin(), iter));
		node->right = reConstructBinaryTree(
			vector<int>(pre.cend() - (vin.cend() - (iter + 1)), pre.cend()),
			vector<int>(iter + 1, vin.cend()));
		return node;
	}
};