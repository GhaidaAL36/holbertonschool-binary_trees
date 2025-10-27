#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Description: if parent already has a right-child, the new node must
 * take its place, and the old right-child must be set as the right-child
 * of the new node.
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right;
	binary_tree_t *tmp;

	if (parent == NULL)
		return (NULL);

	right = binary_tree_node(parent, value);

	if (right == NULL)
		return (NULL);

	tmp = parent->right;

	if (tmp != NULL)
	{
		right->right = tmp;
		tmp->parent = right;
	}

	parent->right = right;

	return (right);
}
