#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node,
 * or NULL if node is NULL or has no uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand_parent;

	if (node == NULL || !node->parent || !node->parent->parent)
		return (NULL);

	grand_parent = node->parent->parent;

	if (grand_parent->left == node->parent)
		return (grand_parent->right);
	else if (grand_parent->right == node->parent)
		return (grand_parent->left);
	else
		return (NULL);
}
