#include "lists.h"
#include <stdio.h>

/**
 *reverse_listint - reverses a listint_t
 *@head: double pointer to list
 *Return: pointer to first node of reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL, *next = NULL;

if (head == NULL)
return (NULL);

while (*head != NULL)
{
next = (*head)->next;
(*head)->next = prev;
prev = *head;
*head = next;
}
*head = prev;
return (*head);
}

/**
 *list_len - prints elements in a linked list
 *@h: first element of the list
 *Return: number of elements in linked list
 */
size_t list_len(const listint_t *h)
{
size_t count = 0;

while (h != NULL)
{
count++;
h = h->next;
}
return (count);
}

/**
 *is_palindrome - checks if a singly linked list is a palindrome
 *@head: double pointer to head of linked list
 *Return: 0 if its palindrome or 1 otherwise
 */
int is_palindrome(listint_t **head)
{
size_t midd, i, j, len;
listint_t *temp, *reversed, *first_half;

if (*head == NULL || head == NULL || **head == NULL)
return (1);

len = list_len(*head);
if (len >= 2)
{
if (len % 2 == 0)
midd = len / 2;
else
midd = len / 2 + 1;
}
else
return (1); 

temp = *head;
for (i = 0; i <= midd; i++)
{
temp = temp->next;
}
reversed = reverse_listint(&temp);

first_half = *head;
for (j = 0; reversed != NULL; j++)
{
if (reversed->n != first_half->n)
return (0);
else
{
reversed = reversed->next;
first_half = first_half->next;
}
}
return (1);
}
