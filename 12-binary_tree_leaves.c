#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 *
 * Return: number of leaves in the tree, 0 if tree is NULL
 * Description: A leaf is a node with no children (both left and right are NULL)
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Check if current node is a leaf (no children) */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* Recursively count leaves in left and right subtrees */
    return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
