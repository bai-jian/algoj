#include "BinaryTree.h"

TreeNode *BinaryTree::invert(TreeNode *root)
{
	if (root != nullptr)
	{
		TreeNode *left = invert(root->left);
		TreeNode *right = invert(root->right);
		root->left = right;
		root->right = left;
	}
	return root;
}

TreeNode *BinarySearchTree::search(TreeNode *root, int key)
{
	TreeNode *node = root;
	while (node)
	{
		if (key == node->val)
			break;
		else if (key < node->val)
			node = node->left;
		else
			node = node->right;
	}
	return node;
}

TreeNode *BinarySearchTree::min(TreeNode *root)
{
	if (root == nullptr)
		return nullptr;
	TreeNode *node = root;
	while (node->left)
		node = node->left;
	return node;
}

TreeNode *BinarySearchTree::max(TreeNode *root)
{
	if (root == nullptr)
		return nullptr;
	TreeNode *node = root;
	while (node->right)
		node = node->right;
	return node;
}

TreeNode *BinarySearchTree::insert(int key)
{
	TreeNode *node = root, **link = &root;
	while (node)
	{
		if (key == node->val)
			return root;
		if (key < node->val)
			link = &node->left, node = node->left;
		else
			link = &node->right, node = node->right;
	}
	*link = new TreeNode(key);
	return root;
}

TreeNode *BinarySearchTree::erase(int key)
{
	TreeNode *node = root, **link = &root;
	while (node)
	{
		if (key == node->val)
			break;
		if (key < node->val)
			link = &node->left, node = node->left;
		else
			link = &node->right, node = node->right;
	}
	if (node != nullptr)
	{
		if (node->left == nullptr)
			*link = node->right;
		else if (node->right == nullptr)
			*link = node->left;
		else
		{
			TreeNode *successor = node->right, *parent = node;
			while (successor->left)
			{
				parent = successor;
				successor = successor->left;
			}
			if (parent != node)
			{
				parent->left = successor->right;
				successor->right = node->right;
			}
			successor->left = node->left;
			*link = successor;
		}
		delete node;
	}
	return root;
}

