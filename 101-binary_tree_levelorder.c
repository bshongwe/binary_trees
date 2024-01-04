#include "binary_trees.h"

/**
 * binary_tree_levelorder - Func goes through binary tree
 * using level-order traversal
 *
 * @tree: Pointer to root node of tree to traverse
 * @func: Pointer to a function to call for each node.
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue = NULL;
	size_t bin_f = 0, bin_r = 0;

	if (!tree || !func)
	{
		return;
	}

	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (!queue)
	{
		return;
	}

	queue[bin_r++] = (binary_tree_t *)tree;

	while (bin_f < bin_r)
	{
		const binary_tree_t *node = queue[bin_f++];

		func(node->n);

		if (node->left)
			queue[bin_r++] = node->left;
		if (node->right)
			queue[bin_r++] = node->right;
	}

	free(queue);
}
