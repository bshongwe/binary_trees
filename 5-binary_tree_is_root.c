#include "binary_trees.h"

/**
 * binary_tree_is_root - Func checks if node is root of binary tree.
 *
 * @node: Pointer to node to check.
 *
 * Return: If the node is a root (-1), otherwise return 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
	{
		return (0);
	}

	return (1);
}
