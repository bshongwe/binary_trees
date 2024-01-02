#include "binary_trees.h"

/**
 * binary_tree_insert_left - Func inserts node as left-child
 *                           of another in binary tree.
 *
 * @parent: Pointer to node to insert left-child in.
 * @value: Value to store in the new node.
 *
 * Return: parent is NULL or error occurs (NULL),
 *         pointer to the new node (success).
 *
 * Description: If parent already has left-child, new node takes
 *              its place and the old left-child is set as
 *              left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
