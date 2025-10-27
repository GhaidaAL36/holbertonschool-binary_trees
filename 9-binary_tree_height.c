#include "binary_trees.h"
#include <stdlib.h>

/**
	* binary_tree_height - Measures the height of a binary tree
	* @tree: Pointer to the root node of the tree to measure
	*
	* Return: Height of the tree in edges, or 0 if tree is NULL
	*
	* Description: Height is the number of edges on the longest path
	* from the node to a leaf. Leaf nodes have height 0. The function
	* uses recursion to calculate the height of left and right subtrees
	* and returns the larger one + 1.
	*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	return (0);

	if (tree->left == NULL && tree->right == NULL)
	return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

