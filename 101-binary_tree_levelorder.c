#include "binary_trees.h"

/**
 * create_node - Func creates new levelorder_queue_t node.
 *
 * @node: Binary tree node for new node.
 *
 * Return: Error (NULL), otherwise return pointer to new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Func frees levelorder_queue_t queue.
 *
 * @head: Pointer to head of queue.
 *
 * Return: void
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pint_push - Func runs function on given binary tree node, pushes
 *             its children into levelorder_queue_t queue.
 *
 * @node: Binary tree node to print and push.
 * @head: Double pointer to queue head.
 * @tail: Double pointer to queue tail.
 * @func: Function pointer to call @node.
 *
 * Return: void
 *
 * Description: Upon malloc failure, exits with status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_node;

	func(node->n);
	if (node->left != NULL)
	{
		new_node = create_node(node->left);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
	if (node->right != NULL)
	{
		new_node = create_node(node->right);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

/**
 * pop - Pops head of levelorder_queue_t queue.
 *
 * @head: Double pointer to head of queue.
 *
 * Return: void
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder - Func traverses binary tree using
 *                          level-order traversal.
 *
 * @tree: Pointer to root node of tree to traverse.
 * @func: Function pointer to call each node.
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
	{
		return;
	}

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		return;
	}

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
