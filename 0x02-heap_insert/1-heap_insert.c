#include "binary_trees.h"

/**
 *heap_insert - function that inserts a value into a Max Binary Heap
 *@root: double pointer to the root node of the Heap
 *@value: is the value stored in the node to be inserted
 *Return: pointer to inserted node or NULL if fail
 **/
heap_t *heap_insert(heap_t **root, int value)
{
  heap_t *newN = (heap_t *) malloc(sizeof(heap_t));
  if (newN == NULL)
    return NULL;

  if (root == NULL || *root == NULL)
  {
    newN = binary_tree_node(*root, value);
    *root = newN;
    return (*root);
  }
  
}


void plevel(const binary_tree_t *tree, void (*func)(int), int level);
/**
 *binary_tree_levelorder - goes through a binary tree using lv-order traversal
 *@tree: pointer to the root node of the tree to traverse
 *@func: is a pointer to a function to call for each node
 **/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
  int height = 0, level = 0;

  if (!tree || !func)
    return;
  height = binary_tree_height(tree) + 1;
  for (level = 1; level <= height; level++)
    plevel(tree, func, level);
}
/**
 * plevel - print node, especific level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * @level: level to print
 */
void plevel(const binary_tree_t *tree, void (*func)(int), int level)
{
  binary_tree_t *nl = tree->left, *nr = tree->right;

  if (level == 1)
    func(tree->n);
  else
    plevel(nl, func, level - 1), plevel(nr, func, level - 1);
}

/**
 *binary_tree_height - measures the height of a binary tree
 *@tree: pointer to root node of the tree measure the height
 *Return: if tree is NULL return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
  size_t height1 = 0, height2 = 0;

  if (!tree || (!tree->left && !tree->right))
    return (0);

  height1 = binary_tree_height(tree->left);
  height2 = binary_tree_height(tree->right);

  if (height1 < height2)
    return (height2 + 1);
  return (height1 + 1);
}
