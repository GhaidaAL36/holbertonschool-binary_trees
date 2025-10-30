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
 * main - Entry point for testing binary_tree_uncle function
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root, *node, *uncle;

	/* Create a test tree */
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->left = create_node(6);
	root->right->right = create_node(7);

	/* Test case 1: Node with uncle (left side) */
	printf("=== Node with uncle (left side) ===\n");
	node = root->left->left; /* Node 4 */
	uncle = binary_tree_uncle(node);
	printf("Node %d: Uncle is ", node->n);
	if (uncle)
		printf("Node %d\n", uncle->n);
	else
		printf("NULL\n");

	/* Test case 2: Node with uncle (right side) */
	printf("\n=== Node with uncle (right side) ===\n");
	node = root->right->right; /* Node 7 */
	uncle = binary_tree_uncle(node);
	printf("Node %d: Uncle is ", node->n);
	if (uncle)
		printf("Node %d\n", uncle->n);
	else
		printf("NULL\n");

	/* Test case 3: Node without uncle (child of root) */
	printf("\n=== Node without uncle (child of root) ===\n");
	node = root->left; /* Node 2 */
	uncle = binary_tree_uncle(node);
	printf("Node %d: Uncle is ", node->n);
	if (uncle)
		printf("Node %d\n", uncle->n);
	else
		printf("NULL\n");

	/* Test case 4: Root node */
	printf("\n=== Root node ===\n");
	uncle = binary_tree_uncle(root);
	printf("Root node: Uncle is ");
	if (uncle)
		printf("Node %d\n", uncle->n);
	else
		printf("NULL\n");

	/* Test case 5: NULL node */
	printf("\n=== NULL node ===\n");
	uncle = binary_tree_uncle(NULL);
	printf("NULL node: Uncle is ");
	if (uncle)
		printf("Node %d\n", uncle->n);
	else
		printf("NULL\n");

	/* Free memory */
	free(root->left->left);
	free(root->left->right);
	free(root->right->left);
	free(root->right->right);
	free(root->left);
	free(root->right);
	free(root);

	return (0);
}
