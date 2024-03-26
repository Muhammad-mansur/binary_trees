#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: size of the tree, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size_t, right_size_t;

	if (tree == NULL)
		return (0);

	left_size_t = binary_tree_size(tree->left);
	right_size_t = binary_tree_size(tree->right);

	return (left_size_t + right_size_t + 1);
}

/**
 * binary_tree_levelorder - traverse a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: Nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	int front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	if (queue == NULL)
		return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		func(current->n);

		if (current->left)
			queue[rear++] = (binary_tree_t *)current->left;

		if (current->right)
			queue[rear++] = (binary_tree_t *)current->right;
	}

	free(queue);
}
