#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node, NULL if not found or node is NULL
 * Description: Uncle is the sibling of the node's parent
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* The uncle is the sibling of the parent */
	return (binary_tree_sibling(node->parent));
}
