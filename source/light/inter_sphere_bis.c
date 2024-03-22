/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:56:32 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/22 18:17:11 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	intersection_sphere_bis(t_vector pos, t_vector dir, t_sphere *sphere,
		double distance)
{
	double	a;
	double	b;
	double	c;
	double	dist;

	a = 1;
	b = prod_scal(pos, dir);
	b -= prod_scal(dir, *sphere->position);
	b *= 2;
	c = prod_scal(pos, pos);
	c -= 2 * prod_scal(pos, *sphere->position);
	c += prod_scal(*sphere->position, *sphere->position);
	c -= (sphere->diameter / 2) * (sphere->diameter / 2);
	dist = sol_quadratic_equation(a, b, c);
	if (dist <= distance && dist > 0.000000001)
		return (1);
	return (0);
}
