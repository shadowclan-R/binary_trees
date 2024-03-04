#include "binary_trees.h"

/**
 * binary_tree_insert_left - Introduces a new node as the left-child of a specified node.
 *
 * @parent: A pointer to the designated node for inserting the left-child.
 * @value: The value to be stored in the new node.
 *
 * Return: A pointer to the newly created node, or NULL if the operation fails.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
        return (NULL);

    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    if (parent->left != NULL)
    {
        new_node->left = parent->left;
        parent->left->parent = new_node;
    }
    parent->left = new_node;

    return (new_node);
}
