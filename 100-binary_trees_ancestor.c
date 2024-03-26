#include "binary_trees.h"

/**
 * find_ancestor - Finds the ancestor of a given node
 * @node: Pointer to the node
 * @ancestor: Pointer to store the ancestor
 *
 * Return: Void
 */
void find_ancestor(const binary_tree_t *node, binary_tree_t **ancestor)
{
    while (node)
    {
        *ancestor = (binary_tree_t *)node;
        node = node->parent;
    }
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes,
 * or NULL if no common ancestor was found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
    binary_tree_t *ancestor1 = NULL, *ancestor2 = NULL;

    find_ancestor(first, &ancestor1);
    find_ancestor(second, &ancestor2);

    while (ancestor1)
    {
        binary_tree_t *temp;

	temp = ancestor2;
        while (temp)
        {
            if (ancestor1 == temp)
                return (ancestor1);
            temp = temp->parent;
        }
        ancestor1 = ancestor1->parent;
    }

    return (NULL);
}
