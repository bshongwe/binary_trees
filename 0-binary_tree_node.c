#include "binary_trees.h"

/**
 * binary_tree_node - Func creates binary tree node
 *
 * @parent: Pointer to parent of node to create
 * @value: New node value
 *
 * Return: Error (NULL), new node pointer (Success)
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
