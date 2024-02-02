/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 06:38:35 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/02 18:36:22 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vector	*new_vector(t_decimal *x, t_decimal *y, t_decimal *z)
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

t_vector *extract_vector(char *str)
{
	char **split;
	t_decimal	*x;
	t_decimal	*y;
	t_decimal	*z;

	split = ft_split(str, ',');
	if (!split || split_length(split) != 3)
		return (NULL);
	x = extract_decimal(split[0]);
	y = extract_decimal(split[1]);
	z = extract_decimal(split[2]);
	p_free_splited_str(split);
	return (new_vector(x, y, z));
}

void	clear_vector(t_vector *vector)
{
	clear_decimal(vector->x);
	clear_decimal(vector->y);
	clear_decimal(vector->z);
	free(vector);
}