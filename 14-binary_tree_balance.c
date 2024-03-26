#include "binary_trees.h"

/**
 * binary_tree_height_t - calc. the height of the binary tree
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

	return ((left_height_t > right_height_t
				? left_height_t : right_height_t) + 1);
}


/**
 * binary_tree_balance - balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor of a binary tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height_t, right_height_t;

	if (tree == NULL)
		return (0);

	left_height_t = binary_tree_height(tree->left);
	right_height_t = binary_tree_height(tree->right);

	return (int)(left_height_t - right_height_t);
}
