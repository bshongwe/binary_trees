#include "binary_trees.h"

/**
 * binary_tree_postorder - Func traverses binary tree
 * using post-order traversal.
 *
 * @tree: Pointer to root node of tree to traverse.
 * @func: Pointer to function to call each node.
 *
 * Return: Void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
