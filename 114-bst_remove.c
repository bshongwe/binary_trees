#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Func prints minimum value of BST.
 *
 * @root: Pointer to BST root node.
 *
 * Return: Minimum BST value.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return (root);
}

/**
 * bst_delete - Func deletes node from BST.
 *
 * @root: Pointer to BST root node.
 * @node: Pointer to node to delete from the BST.
 *
 * Return: Pointer to new root node after deleting.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* For no children or right-child */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* For left-child */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* For two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Func removes BST node recursively.
 *
 * @root: Pointer to BST root node to remove node from.
 * @node: Pointer to current BST node.
 * @value: BST value to remove.
 *
 * Return: Pointer to BST root node after deleting.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
		{
			return (bst_delete(root, node));
		}
		if (node->n > value)
		{
			return (bst_remove_recursive(root, node->left, value));
		}
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Func removes BST node.
 *
 * @root: Pointer to BST root node to remove.
 * @value: BST value to remove.
 *
 * Return: Pointer to new root node after deleting.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
