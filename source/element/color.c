/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 06:43:55 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:37:50 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	is_color_compatible(char *str)
{
	char	**split;

	split = ft_split(str, ',');
	if (!split)
		return (FAILURE);
	if (split_length(split) != 3)
	{
		p_free_splited_str(split);
		return (FAILURE);
	}
	if (!is_int_compatible(split[0]) || !is_int_compatible(split[1])
		|| !is_int_compatible(split[2]))
	{
		p_free_splited_str(split);
		return (FAILURE);
	}
	p_free_splited_str(split);
	return (SUCCESS);
}

t_color	*new_color(int red, int green, int blue)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->red = red;
	color->green = green;
	color->blue = blue;
	return (color);
}

t_color	*extract_color(char *str)
{
	t_color	*color;
	char	**split;

	split = ft_split(str, ',');
	if (!split)
		return (NULL);
	color = new_color(ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
	p_free_splited_str(split);
	return (color);
}

int	color_to_int(t_color color)
{
	int	int_color;

	int_color = ((color.red << 16) + (color.green << 8) + color.blue);
	return (int_color);
}

void	clear_color(t_color *color)
{
	if (color)
		free(color);
}
