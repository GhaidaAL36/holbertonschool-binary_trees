#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t size;

    /* Create a basic tree */
    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    root->left->left = binary_tree_node(root->left, 4);
    root->left->right = binary_tree_node(root->left, 5);

    /* Test the size function */
    size = binary_tree_size(root);
    printf("Size of tree: %lu\n", size);

    /* Test with NULL */
    size = binary_tree_size(NULL);
    printf("Size of NULL tree: %lu\n", size);

    return (0);
}
