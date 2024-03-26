#include "binary_trees.h"

/**
 * bst_search - searches for a value in a binary search tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 *
 * Return: a pointer to the node containing the value,
 * or NULL if not found
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return (tree);

	if (value < tree->n)
		return bst_search(tree->left, value);

	return bst_search(tree->right, value);
}
