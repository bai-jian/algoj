#include <vector>

using std::vector;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
	TreeNode *root;

public:
	BinaryTree() : root(nullptr) {}

	TreeNode *invert(TreeNode *root);
};

class BinarySearchTree
{
private:
	TreeNode *root;

public:
	BinarySearchTree() : root(nullptr) {}

	TreeNode *search(TreeNode *root, int key);
	TreeNode *min(TreeNode *root);
	TreeNode *max(TreeNode *root);

	TreeNode *insert(int key);
	TreeNode *erase(int key);

	vector<int> inorderTraversal(TreeNode *root);
	vector<int> preorderTraversal(TreeNode *root);
	vector<int> postorderTraversal(TreeNode *root);
};
