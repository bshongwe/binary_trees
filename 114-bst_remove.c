#include "binary_trees.h"

/**
 * successor - Func gets next successor on right subtree
 *
 * @node: Tree to check
 *
 * Return: Min value of tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
		return (0);
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * two_children - Func gets next successor using right subtree
 * min value, and then replaces node value for successor
 *
 * @root: node tat has two children
 *
 * Return: Present value found
 */
int two_children(bst_t *root)
{
	int new_value = 0;

	new_value = successor(root->right);
	root->n = new_value;
	return (new_value);
}

/**
 *remove_type - Func removes node depending of its children

 *@root: node to remove

 *Return: if it has no children (0), or present value
 */
int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}

/**
 * bst_remove - Func removes node from BST
 *
 * @root: Root node of tree
 * @value: Root node with value to remove
 *
 * Return: New BST value after deletion
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
	{
		return (NULL);
	}
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
	{
		return (NULL);
	}
	return (root);
}
