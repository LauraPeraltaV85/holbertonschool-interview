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
 * sorted_array_to_avl - sorts array into avl binary tree
 *
 * @array: The array to sorted
 * @size: Size of the array
 * Return: pointer to root node of the created tree 
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
  size_t half = size/2;
  avl_t *root;
  
  
  binary_tree_node(root, array[half]);

  
  
  

}
