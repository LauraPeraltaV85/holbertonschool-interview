#include "lists.h"

/**
 * insert_node - prints all elements of a listint_t list
 * @head: pointer to head of list
 * @number: data in new node
 * Return: address of the new node or NULL if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *newnode, *temp;

if (head == NULL)
return (NULL);

newnode = malloc(sizeof(listint_t));
if (newnode == NULL)
return (NULL);

newnode->n = number;
newnode->next = NULL;
if (newnode->n < (*head)->n)
{
newnode->next = *head;
*head = newnode;
}
else
{
temp = *head;
while (temp != NULL)
{
if (temp == NULL)
return (NULL);
temp = temp->next;
if (temp->next == NULL || temp->next->n > newnode->n)
{
newnode->next = temp->next;
temp->next = newnode;
break;
}
}
}
return (newnode);
}
