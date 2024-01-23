/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:13:56 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/23 02:08:05 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static t_element_identifier	get_element_type(char *str)
{
	t_element_identifier	type;

	if (ft_strncmp(str, "A", 2) == 0)
		type = ambient_light;
	else if (ft_strncmp(str, "C", 2) == 0)
		type = camera;
	else if (ft_strncmp(str, "L", 2) == 0)
		type = light;
	else if (ft_strncmp(str, "sp", 3) == 0)
		type = sphere;
	else if (ft_strncmp(str, "pl", 3) == 0)
		type = plane;
	else if (ft_strncmp(str, "cy", 3) == 0)
		type = cylinder;
	return (type);
}

t_element	*get_element(char *line, t_element_list *element_list)
{
	t_element	*element;
	char		**parts;

	parts = ft_split_white_space(line);
	if (!parts)
		return (NULL);
	element = init_element();
	if (!element)
	{
		p_free_splited_str(parts);
		return (NULL);
	}
	element->identifier = get_element_type(parts[0]);
	if (element->identifier == unknown)
	{
		free(element);
		p_free_splited_str(parts);
		return (NULL);
	}
	process_element(parts, element);
	p_free_splited_str(parts);
	return (element);
}
