#include "binary_trees.h"
#include <stdlib.h>

/**
	* binary_tree_inorder - Goes through a binary tree using in-order traversal
	* @tree: Pointer to the root node of the tree to traverse
	* @func: Pointer to a function to call for each node. The value of the node
	*        is passed as a parameter to this function
	*
	* Description: In-order traversal means visiting the left subtree first,
	* then the current node, followed by the right subtree. If tree or func
	* is NULL, the function does nothing.
	*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}

