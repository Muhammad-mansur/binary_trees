#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 * @tree: node to be counted.
 *
 * Return: number of leaves.
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_leaves_t, right_leaves_t;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_leaves_t = binary_tree_leaves(tree->left);
	right_leaves_t = binary_tree_leaves(tree->right);

	return left_leaves_t + right_leaves_t;
}
