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
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	int front = 0, rear = 0;
	int complete = 1;

	if (tree == NULL)
		return (0);

	queue = malloc(binary_tree_size(tree) * sizeof(binary_tree_t *));
	if (queue == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current;

		current = queue[front++];
		if (current == NULL)
		{
			while (front < rear)
			{
				if (queue[front++] != NULL)
				{
					complete = 0;
					break;
				}
			}
		}
		else
		{
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}

	free(queue);

	return (complete);
}
