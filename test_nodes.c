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
	return (node);
}

/**
 * main - Entry point for testing binary_tree_nodes function
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	binary_tree_t *single_node;
	size_t nodes;

	/* Test case 1: Perfect tree of height 1 (1 node with children) */
	printf("=== Perfect tree of height 1 ===\n");
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	nodes = binary_tree_nodes(root);
	printf("Nodes with children: %lu\n", nodes);

	/* Test case 2: Perfect tree of height 2 (3 nodes with children) */
	printf("\n=== Perfect tree of height 2 ===\n");
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->left = create_node(6);
	root->right->right = create_node(7);
	nodes = binary_tree_nodes(root);
	printf("Nodes with children: %lu\n", nodes);

	/* Test case 3: Single node (0 nodes with children) */
	printf("\n=== Single node ===\n");
	single_node = create_node(10);
	nodes = binary_tree_nodes(single_node);
	printf("Nodes with children: %lu\n", nodes);

	/* Test case 4: NULL tree */
	printf("\n=== NULL tree ===\n");
	nodes = binary_tree_nodes(NULL);
	printf("Nodes with children: %lu\n", nodes);

	/* Test case 5: Not perfect tree */
	printf("\n=== Not perfect tree ===\n");
	free(root->right->right); /* Remove one node */
	nodes = binary_tree_nodes(root);
	printf("Nodes with children: %lu\n", nodes);

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
