#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 +
		binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * get_parent - Finds the parent where the new node will be inserted
 * @root: Pointer to the root of the heap
 * @index: Index of the node to insert
 *
 * Return: Pointer to the parent node
 */
heap_t *get_parent(heap_t *root, size_t index)
{
	size_t bit;

	bit = 1;
	while (bit <= index)
		bit <<= 1;
	bit >>= 2;

	while (bit > 1)
	{
		if (index & bit)
			root = root->right;
		else
			root = root->left;

		bit >>= 1;
	}

	return (root);
}

/**
 * heapify_up - Restores the Max Heap property
 * @node: Pointer to the inserted node
 */
void heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;

		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root of the heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent;
	heap_t *new;
	size_t size;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);

	parent = get_parent(*root, size + 1);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;

	heapify_up(new);

	return (new);
}
