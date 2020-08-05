#include "binary_trees.h"

/**
 * binary_tree_node - This function creates a binary tree node
 * @parent: node to add new node
 * @value: value to insert in new node
 * Return: poointer to the new node
 */
avl_t *binary_tree_node(avl_t *parent, int value)
{
  avl_t *newnode;

  newnode = malloc(sizeof(avl_t));
  if (newnode == NULL)
    return (NULL);

  newnode->n = value;
  newnode->parent = parent;
  newnode->left = NULL;
  newnode->right = NULL;
  return (newnode);
}

/**
 * heap_insert - Function to insert a node for a binary tree
 * @root: this is the head of our binary tree
 * @value: This is the value of each element in our binary tree
 * Return: pointer to new node or NULL if it fails
 */
avl_t *heap_insert(avl_t **root, int size, int *array)
{
  int half = size/2;
  avl_t *new = NULL;


  if (*root)
    {
      if (half >= 1)
	{
	  root->left = binary_tree_node(*root, array[half - 1]);
	  /*new = new->left;*/
	  new->left = heap_insert(root, half-1, array);
	  /* root->right = heap_insert(&array[half + 1], new_size);*/
	}
    }
  else
    {
      *root = binary_tree_node(*root, array[half - 1]);
      new = *root;
    }
  return (new);
}


/**
 * sorted_array_to_avl - sorts array into avl binary tree
 *
 * @array: The array to sorted
 * @size: Size of the array
 * Return: pointer to root node of the created tree 
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
  avl_t *root = NULL;

  root = heap_insert(&root, size, array);
      /* new_size = size - half;     */

  return root;
}
