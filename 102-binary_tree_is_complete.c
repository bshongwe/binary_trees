#include "binary_trees.h"

/**
 * binary_tree_is_complete - Func checks if binary tree is complete
 *
 * @tree: Pointer to root node of binary tree to check.
 *
 * Return: If the tree is complete (1), otherwise return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nod_s = 0, i = 0;
	const binary_tree_t **queue = NULL;

	if (!tree)
	{
		return (0);
	}

	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (!queue)
	{
		return (0);
	}

	queue[0] = tree;
	nod_s++;

	while (i < nod_s)
	{
		const binary_tree_t *node = queue[i++];

		if (node->left)
		{
			queue[nod_s++] = node->left;
			if (!node->right)
			{
				return (0);
			}
		}

		if (node->right)
		{
			queue[nod_s++] = node->right;
			if (!node->left)
				return (0);
		}
	}

	free(queue);
	return (1);
}
