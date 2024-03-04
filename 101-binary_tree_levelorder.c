#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the binary tree. If the tree is empty, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		l = 1 + binary_tree_height(tree->left);
	if (tree->right)
		r = 1 + binary_tree_height(tree->right);

	return ((l > r) ? l : r);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 *
 * @tree: Pointer to the node to measure the depth of.
 *
 * Return: The depth of the node. If tree is NULL, return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Creates a linked list of nodes at the specified depth.
 *
 * @head: Pointer to the head of the linked list.
 * @tree: Pointer to the node to store in the linked list.
 * @level: Depth of the node.
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new, *aux;

	new = malloc(sizeof(link_t));
	if (new == NULL)
		return;

	new->n = level;
	new->node = tree;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		aux = *head;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}

/**
 * recursion - Recursively traverses the binary tree and stores each node in a linked list.
 *
 * @head: Pointer to the head of the linked list.
 * @tree: Pointer to the current node.
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Performs level-order traversal of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head = NULL, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);
	recursion(&head, tree);

	while (count <= height)
	{
		aux = head;
		while (aux != NULL)
		{
			if (count == aux->n)
				func(aux->node->n);
			aux = aux->next;
		}
		count++;
	}

	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
