#include "binary_trees.h"

/**
 * check_sub_tree_Left - Checks if all nodes are smaller than or equal to
 * the specified root value.
 *
 * @node: Pointer to the node to verify the condition.
 * @max: Value to compare.
 *
 * Return: 1 if all nodes are smaller or equal, 0 otherwise.
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int left = 0, right = 0;

	if (node == NULL)
		return (1);

	if (node->n >= max)
		return (0);

	left = check_sub_tree_Left(node->left, max);
	right = check_sub_tree_Left(node->right, max);

	if (left == right && left == 1)
		return (1);

	return (0);
}

/**
 * check_sub_tree_Right - Checks if all nodes are bigger than or equal to
 * the specified root value.
 *
 * @node: Pointer to the node to verify the condition.
 * @min: Value to compare.
 *
 * Return: 1 if all nodes are bigger or equal, 0 otherwise.
 */
int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int left = 0, right = 0;

	if (node == NULL)
		return (1);

	if (node->n <= min)
		return (0);

	left = check_sub_tree_Right(node->left, min);
	right = check_sub_tree_Right(node->right, min);

	if (left == right && left == 1)
		return (1);

	return (0);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a Binary Search Tree (BST).
 * The process involves verifying that the left node is smaller than the root
 * and the right node is bigger than the root. Then, it checks if the left
 * subtree has nodes smaller than the root and the right subtree has bigger
 * nodes than the root.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if it is a BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, left = 2, right = 2;

	if (tree == NULL)
		return (0);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n < tree->n)
		return (0);

	if (tree->left && tree->left->n < tree->n)
	{
		var = check_sub_tree_Left(tree->left, tree->n);
		if (var == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}

	if (tree->right && tree->right->n > tree->n)
	{
		var = check_sub_tree_Right(tree->right, tree->n);
		if (var == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}

	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}

	return (1);
}
