#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_node - Creates a new binary tree node
 * @value: Integer value to store in the node
 *
 * Return: Pointer to the new node, or NULL if allocation fails
 */
binary_tree_t *create_node(int value)
{
    binary_tree_t *node = malloc(sizeof(binary_tree_t));
    
    if (node)
    {
        node->n = value;
        node->parent = NULL;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

/**
 * main - Entry point for testing the binary_tree_size function
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *single_node;
    size_t size;

    /* Create a test tree with 6 nodes */
    root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);

    /* Test case 1: Tree with multiple nodes */
    size = binary_tree_size(root);
    printf("Size of tree with 6 nodes: %lu\n", size);

    /* Test case 2: NULL tree */
    size = binary_tree_size(NULL);
    printf("Size of NULL tree: %lu\n", size);

    /* Test case 3: Single node tree */
    single_node = create_node(10);
    size = binary_tree_size(single_node);
    printf("Size of single node tree: %lu\n", size);

    /* Free allocated memory */
    free(root->right->left);
    free(root->left->right);
    free(root->left->left);
    free(root->right);
    free(root->left);
    free(root);
    free(single_node);

    return (0);
}
