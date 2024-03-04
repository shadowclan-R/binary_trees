#include "binary_trees.h"

/**
 * binary_tree_delete - Removes an entire binary tree from memory.
 *
 * @tree: A pointer to the root node of the tree to be removed.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binary_tree_delete(tree->left);
			binary_tree_delete(tree->right);
		}
		free(tree);
	}

}
