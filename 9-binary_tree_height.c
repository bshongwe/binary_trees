#include "binary_trees.h"

/**
 * binary_tree_height - Func measures height of binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL (0), else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t ht_l = 0, ht_r = 0;

		ht_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		ht_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((ht_l > ht_r) ? ht_l : ht_r);
	}
	return (0);
}
