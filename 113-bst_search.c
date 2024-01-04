#include "binary_trees.h"

/**
 * bst_search - Func searches for value in binary search tree.
 *
 * @tree: Pointer to root node of BST to search.
 * @value: Value to search for in BST.
 *
 * Return: Tree is  NULL or not found (NULL), value node pointer (Success).
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
		{
			return ((bst_t *)tree);
		}
		if (tree->n > value)
		{
			return (bst_search(tree->left, value));
		}
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
