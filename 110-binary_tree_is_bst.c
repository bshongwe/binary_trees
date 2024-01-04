#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Func checks if binary tree is valid binary search tree.
 *
 * @tree: Pointer to root node of binary tree to check.
 * @lo: Value of smallest node in current search.
 * @hi: Value of largest node in current search.
 *
 * Return: If the tree is a valid BST (1), otherwise return 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
		{
			return (0);
		}
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
				is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Func checks if binary tree is valid BST.
 *
 * @tree: Pointer to root node of tree to check.
 *
 * Return: If the tree is a valid BST (1), otherwise return 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
