/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:14:55 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/22 18:21:24 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vector	sum_vec(t_vector u, t_vector v)
{
	t_vector	sum;

	sum.x = u.x + v.x;
	sum.y = u.y + v.y;
	sum.z = u.z + v.z;
	return (sum);
}

t_vector	diff_vec(t_vector u, t_vector v)
{
	t_vector	diff;

	diff.x = u.x - v.x;
	diff.y = u.y - v.y;
	diff.z = u.z - v.z;
	return (diff);
}

t_vector	prod_nb_vec(double k, t_vector u)
{
	t_vector	prod;

	prod.x = k * u.x;
	prod.y = k * u.y;
	prod.z = k * u.z;
	return (prod);
}

double	prod_scal(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double	norm_vec(t_vector u)
{
	return (sqrt(prod_scal(u, u)));
}
