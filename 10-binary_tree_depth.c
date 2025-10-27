#include "binary_trees.h"
#include <stdlib.h>

/**
	* binary_tree_depth - Measures the depth of a node in a binary tree
	* @tree: Pointer to the node to measure
	*
	* Return: Depth of the node (number of edges to the root), or 0 if tree is NULL
	*
	* Description: The depth is the number of edges from the node to the tree's root.
	* A root node has depth 0. The function walks up the tree via parent pointers.
	*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
	return (0);

	while (tree->parent != NULL)
	{
	depth++;
	tree = tree->parent;
	}

	return (depth);
}

