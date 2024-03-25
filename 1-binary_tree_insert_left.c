#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node as the
 * left-child of another node
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the created node, or
 * NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_n = malloc(sizeof(binary_tree_t));
	if (new_n == NULL)
	{
		return (NULL);
	}

	new_n->n = value;
	new_n->parent = parent;
	new_n->right = NULL;

	if (parent->left != NULL)
	{
		new_n->left = parent->left;
		parent->left->parent = new_n;
	}
	else
	{
		new_n->left = NULL;
	}

	parent->left = new_n;

	return (new_n);
}
