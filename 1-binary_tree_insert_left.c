#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Description: If parent already has a left-child, the new node
 *              takes its place and the old left-child becomes
 *              the left-child of the new node.
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left;
	binary_tree_t *tmp;

	if (parent == NULL)
		return (NULL);

	left = binary_tree_node(parent, value);

	if (left == NULL)
		return (NULL);

	tmp = parent->left;
	if (tmp != NULL)
	{
		left->left = tmp;
		tmp->parent = left;
	}

	parent->left = left;

	return (left);


}
