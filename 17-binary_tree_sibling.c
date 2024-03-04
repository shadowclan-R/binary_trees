#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a given node.
 *
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: NULL if node is NULL, its parent is NULL, or it has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
