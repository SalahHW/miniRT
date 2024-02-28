/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 06:38:35 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/27 16:48:22 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int is_vector_compatible(char *str)
{
	char **split;

	split = ft_split(str, ',');
	if (!split)
		return (FAILURE);
	if (split_length(split) != 3)
	{
		p_free_splited_str(split);
		return (FAILURE);
	}
	if (!is_double_compatible(split[0]) || !is_double_compatible(split[1]) || !is_double_compatible(split[2]))
	{
		p_free_splited_str(split);
		return (FAILURE);
	}
	p_free_splited_str(split);
	return (SUCCESS);
}

t_vector	*new_vector(double x, double y, double z)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_vector	*extract_vector(char *str)
{
	char	**split;
	double	x;
	double	y;
	double	z;

	split = ft_split(str, ',');
	if (!split || split_length(split) != 3)
		return (NULL);
	x = string_to_double(split[0]);
	y = string_to_double(split[1]);
	z = string_to_double(split[2]);
	p_free_splited_str(split);
	return (new_vector(x, y, z));
}

void	clear_vector(t_vector *vector)
{
	free(vector);
}