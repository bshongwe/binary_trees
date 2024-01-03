#include "binary_trees.h"

/**
 * binary_tree_depth - Func measures depth of binary tree
 *
 * @tree: Node to measure
 *
 * Return: The depth of the tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t i = 0;

	if (!tree)
	{
		return (0);
	}

	if (tree->parent)
	{
		i = binary_tree_depth(tree->parent);
		i++;
	}
	return (i);
}

/**
 * binary_tree_height - Func measures height of binary tree
 *
 * @tree: Node to measure
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t ht_l;
	size_t ht_r;

	if (!tree)
	{
		return (0);
	}

	ht_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	ht_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (ht_l > ht_r ? ht_l : ht_r);
}

/**
 * is_perfect - Func checks if binary tree is perfect
 *
 * @tree: Tree to check
 * @height: Height of tree to check
 *
 * Return: Integer
 */
int is_perfect(const binary_tree_t *tree, int height)
{
	int depth = 0;

	if (!tree)
	{
		return (0);
	}

	if (!tree->left && !tree->right)
	{
		depth = binary_tree_depth(tree);
		if (depth == height)
		{
			return (1);
		}
		return (0);
	}

	return (is_perfect(tree->left, height) && is_perfect(tree->right, height));
}

/**
 * binary_tree_is_perfect - Func checks if binary tree is perfect
 *
 * @tree: Tree to check
 *
 * Return: integer
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;

	if (!tree)
	{
		return (0);
	}

	height = binary_tree_height(tree);

	return (is_perfect(tree, height));
}
