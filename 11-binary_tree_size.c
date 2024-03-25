#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to be measured.
 *
 * Return: size of the tree.
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
