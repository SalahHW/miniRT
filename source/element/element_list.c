/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:15:54 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/05 08:29:45 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static void	update_list_count(t_element_list *list, t_element_identifier id)
{
	list->count++;
	if (id == ambient_light)
		list->ambient_light_count++;
	else if (id == camera)
		list->camera_count++;
	else if (id == light)
		list->light_count++;
	else if (id == sphere)
		list->sphere_count++;
	else if (id == plane)
		list->plane_count++;
	else if (id == cylinder)
		list->cylinder_count++;
}

t_element_list	*init_element_list(void)
{
	t_element_list	*element_list;

	element_list = malloc(sizeof(t_element_list));
	if (!element_list)
		return (NULL);
	element_list->head = NULL;
	element_list->tail = NULL;
	element_list->count = 0;
	element_list->ambient_light_count = 0;
	element_list->camera_count = 0;
	element_list->light_count = 0;
	element_list->sphere_count = 0;
	element_list->plane_count = 0;
	element_list->cylinder_count = 0;
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
	update_list_count(list, new_element->identifier);
}

void	clear_element_list(t_element_list *list)
{
	t_element	*element;
	t_element	*next_element;

	element = list->head;
	while (element)
	{
		next_element = element->next;
		clear_element(element);
		element = next_element;
	}
	free(list);
}
