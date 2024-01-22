/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:14:10 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/22 02:14:17 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_element	*init_element(void)
{
	t_element	*new_element;

	new_element = (t_element *)malloc(sizeof(t_element));
	if (!new_element)
		return (NULL);
	new_element->identifier = unknown;
	new_element->next = NULL;
	return (new_element);
}
