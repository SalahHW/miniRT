/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 06:38:35 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/06 17:45:23 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

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
	x = extract_decimal(split[0]);
	y = extract_decimal(split[1]);
	z = extract_decimal(split[2]);
	p_free_splited_str(split);
	return (new_vector(x, y, z));
}

void	clear_vector(t_vector *vector)
{
	free(vector);
}