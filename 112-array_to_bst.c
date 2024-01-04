#include "binary_trees.h"

/**
 * array_to_bst - Fun builds binary search tree from an array.
 *
 * @array: Pointer to first element of array.
 * @size: Number of elements in @array.
 *
 * Return: Pointer to root node of built BST (Success),
 * fail (NULL).
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t a, b;

	if (array == NULL)
	{
		return (NULL);
	}

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break;
		}
		if (b == a)
		{
			if (bst_insert(&tree, array[a]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
