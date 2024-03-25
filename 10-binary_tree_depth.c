#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: nood to be measured.
 *
 * Return: Depth measured.
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth_t = 0;

	while (tree != NULL && tree->parent != NULL)
	{
		tree = tree->parent;
		depth_t++;
	}

	return (depth_t);
}
