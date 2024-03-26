#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp_first = first;
	const binary_tree_t *temp_second = second;

	while (temp_first)
	{
		const binary_tree_t *ancestor = second;

		while (ancestor)
		{
			if (temp_first == ancestor)
				return ((binary_tree_t *)temp_first);
			ancestor = ancestor->parent;
		}
		temp_first = temp_first->parent;
	}

	while (temp_second)
	{
		const binary_tree_t *ancestor = first;

		while (ancestor)
		{
			if (temp_second == ancestor)
				return ((binary_tree_t *)temp_second);
			ancestor = ancestor->parent;
		}
		temp_second = temp_second->parent;
	}

	return (NULL);
}
