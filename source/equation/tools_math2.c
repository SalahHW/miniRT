/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_math2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmartin <flmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:15:08 by jkerbidi          #+#    #+#             */
/*   Updated: 2024/03/22 18:21:24 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vector	prod_vec(t_vector u, t_vector v)
{
	t_vector	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	w = prod_nb_vec(norm_vec(w), w);
	return (w);
}

double	find_sol(double sol1, double sol2)
{
	if (sol1 > 0)
	{
		if (sol2 > 0)
			return (fmin(sol1, sol2));
		return (sol1);
	}
	if (sol2 > 0)
		return (sol2);
	return (0);
}

double	sol_quadratic_equation(double a, double b, double c)
{
	double	delta;
	double	alpha;
	double	truc;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	alpha = -b / (2 * a);
	truc = sqrt(delta) / (2 * a);
	if (delta == 0)
		return (fmax(alpha, 0));
	else
		return (find_sol(alpha - truc, alpha + truc));
	return (0);
}
