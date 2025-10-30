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
 * main - Entry point for testing the binary_tree_leaves function
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *single_node;
    size_t leaves;

    /* Test case 1: Perfect tree of height 1 (3 nodes, 2 leaves) */
    printf("=== Perfect tree of height 1 ===\n");
    root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    leaves = binary_tree_leaves(root);
    printf("Leaves: %lu\n", leaves);

    /* Test case 2: Perfect tree of height 2 (7 nodes, 4 leaves) */
    printf("\n=== Perfect tree of height 2 ===\n");
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);
    leaves = binary_tree_leaves(root);
    printf("Leaves: %lu\n", leaves);

    /* Test case 3: Single node (1 node, 1 leaf) */
    printf("\n=== Single node ===\n");
    single_node = create_node(10);
    leaves = binary_tree_leaves(single_node);
    printf("Leaves: %lu\n", leaves);

    /* Test case 4: NULL tree */
    printf("\n=== NULL tree ===\n");
    leaves = binary_tree_leaves(NULL);
    printf("Leaves: %lu\n", leaves);

    /* Test case 5: Not perfect tree */
    printf("\n=== Not perfect tree ===\n");
    free(root->right->right); /* Remove one leaf */
    leaves = binary_tree_leaves(root);
    printf("Leaves: %lu\n", leaves);

    /* Free memory */
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->left);
    free(root->right);
    free(root);
    free(single_node);

    return (0);
}
