#include "binary_trees.h"

/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height_t, right_height_t;

	if (tree == NULL)
		return (0);

	left_height_t = binary_tree_height(tree->left);
	right_height_t = binary_tree_height(tree->right);

	return ((left_height_t > right_height_t ? left_height_t : right_height_t)+1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, level;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);

	for (level = 0; level < height - 1; level++)
	{
		size_t expected_nodes, count_nodes;
		const binary_tree_t *current;

		expected_nodes = 1 << level;

		count_nodes = 0;
		current = tree;
		while (current != NULL && count_nodes < expected_nodes)
		{
			count_nodes++;
			current = current->left;
		}

		if (count_nodes != expected_nodes)
			return (0);
	}

	return (1);
}
