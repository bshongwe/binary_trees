#include "binary_trees.h"

/**
 * create_node - Func creates new levelorder_queue_t node.
 *
 * @node: Binary tree node for new node.
 *
 * Return: Error (NULL), otherwise, return pointer to new node.
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
 * @head: A pointer to the head of the queue.
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
 * push - Func pushes node to back of levelorder_queue_t queue.
 *
 * @node: Binary tree node to print and push.
 * @head: Head double pointer to queue.
 * @tail: Tail double pointer to queue.
 *
 * Return: void
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node;

	new_node = create_node(node);
	if (new_node == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

/**
 * pop - Func pops head of levelorder_queue_t queue.
 * @head: Double pointer to head of queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_is_complete - Func checks if a binary tree is complete.
 *
 * @tree: Pointer to root node of tree to traverse.
 *
 * Return: If the tree is NULL or not complete (0), otherwise (1).
 *
 * Description: When malloc fails, function exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char fl_g = 0;

	if (tree == NULL)
	{
		return (0);
	}

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (fl_g == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			fl_g = 1;
		if (head->node->right != NULL)
		{
			if (fl_g == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			fl_g = 1;
		pop(&head);
	}
	return (1);
}
