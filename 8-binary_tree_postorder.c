#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_postorder - Goes through a binary tree using post-order
 *                          traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node. The value of the node
 *        is passed as a parameter to this function
 *
 * Description: Post-order traversal means visiting the left subtree first,
 * then the right subtree, followed by the current node. If tree or func is
 * NULL, the function does nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}

