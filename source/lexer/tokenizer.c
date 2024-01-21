/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:13:56 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/21 08:23:46 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static t_element_identifier	get_element_type(char *token_start, char *token_end)
{
	char					*token;
	t_element_identifier	type;

	token = ft_substr(token_start, 0, token_end - token_start);
	if (ft_strncmp(token, "A", 2) == 0)
		type = ambient_light;
	else if (ft_strncmp(token, "C", 2) == 0)
		type = camera;
	else if (ft_strncmp(token, "L", 2) == 0)
		type = light;
	else if (ft_strncmp(token, "sp", 3) == 0)
		type = sphere;
	else if (ft_strncmp(token, "pl", 3) == 0)
		type = plane;
	else if (ft_strncmp(token, "cy", 3) == 0)
		type = cylinder;
	free(token);
	return (type);
}

t_element	*get_element(char *line, t_element_list *element_list)
{
	char		*token_start;
	char		*token_end;
	t_element	*element;

	element = malloc(sizeof(t_element));
	if (!element)
		return (NULL);
	while (*line && is_white_space(*line))
		line++;
	token_start = line;
	while (*line && !is_white_space(*line))
		line++;
	token_end = line;
	if (token_start == token_end)
	{
		free(element);
		return (NULL);
	}
	element->identifier = get_element_type(token_start, token_end);
	process_element(line, element);
	add_element(element_list, element);
	return (element);
}
