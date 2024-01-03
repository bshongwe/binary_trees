#include "binary_trees.h"

/**
 * binary_tree_nodes - Func counts nodes with at least 1 child in binary tree.
 *
 * @tree: Pointer to root node of tree to count number of nodes.
 *
 * Return: If tree is NULL (0), else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node_count = 0;

	if (tree)
	{
		node_count += (tree->left || tree->right) ? 1 : 0;
		node_count += binary_tree_nodes(tree->left);
		node_count += binary_tree_nodes(tree->right);
	}
	return (node_count);
}
