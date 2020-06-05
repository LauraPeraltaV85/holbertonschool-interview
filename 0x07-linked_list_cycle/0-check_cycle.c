#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *check_cycle - check if a singly list has a cycle in it
 *@list: linked list to be checked
 *Return: 0 if there is no cycle or 1 if there is cycle
 */
int check_cycle(listint_t *list)
{
listint_t *n1, *n2;

if (list == NULL || list->next == NULL)
return (0);

n1 = list;
n2 = list;
n1 = n1->next;
n2 = n2->next->next;

while (n2 && n2->next)
{
if (n1 == n2)
return (1);
n1 = n1->next;
n2 = n2->next->next;
}
return (0);
}
