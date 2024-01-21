#include "../../include/miniRT.h"

t_element_list	*init_element_list(void)
{
	t_element_list	*element_list;

	element_list = malloc(sizeof(t_element_list));
	element_list->head = NULL;
	element_list->tail = NULL;
	return (element_list);
}

void	add_element(t_element_list *list, t_element *new_element)
{
	if (!new_element)
		return ;
	new_element->next = NULL;
	if (!list->head)
	{
		list->head = new_element;
		list->tail = new_element;
	}
	else
	{
		list->tail->next = new_element;
		list->tail = new_element;
	}
}

void clear_element_list(t_element_list *list)
{
	t_element *element;
	t_element *next_element;

	element = list->head;
	while (element)
	{
		next_element = element->next;
		free(element);
		element = next_element;
	}
}
