#include "binary_trees.h"

/**
 * binary_tree_leaves - Func counts leaves in binary tree.
 *
 * @tree: Pointer to root node of tree to count leaves of.
 *
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t bin_leaves = 0;

	if (tree)
	{
		bin_leaves += (!tree->left && !tree->right) ? 1 : 0;
		bin_leaves += binary_tree_leaves(tree->left);
		bin_leaves += binary_tree_leaves(tree->right);
	}
	return (bin_leaves);
}
