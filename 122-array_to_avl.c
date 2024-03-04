#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 *
 * @array: Array to create the AVL tree from.
 * @size: Size of the array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 *         or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int i;
	avl_t *root = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
