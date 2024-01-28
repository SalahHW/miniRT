/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 06:38:35 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/28 06:43:07 by sbouheni         ###   ########.fr       */
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

void	clear_vector(t_vector *vector)
{
	clear_decimal(vector->x);
	clear_decimal(vector->y);
	clear_decimal(vector->z);
	free(vector);
}