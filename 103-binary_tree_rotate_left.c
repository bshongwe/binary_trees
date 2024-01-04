#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Func flft-rotates binary tree.
 *
 * @tree: Pointer to root node of binary tree to rotate.
 *
 * Return: Pointer to new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pvt_rn, *temp;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	pvt_rn = tree->right;
	temp = pvt_rn->left;
	pvt_rn->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = pvt_rn;
	pvt_rn->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = pvt_rn;
		else
			temp->right = pvt_rn;
	}

	return (pvt_rn);
}
