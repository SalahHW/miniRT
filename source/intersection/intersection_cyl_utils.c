/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cyl_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:47:38 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/11 16:56:01 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

// Cette fonction sert a delimiter la portion de la face laterale du cylindre 
// car le cylindre a une hauteur FINIE.
int	not_in_range(t_vector intersection, t_cylinder cyl)
{
	t_vector	cp;
	double	prod;
	double	tmp;

	cp = diff_vec(intersection, *cyl.position);
	tmp = cyl.height / 2;
	prod = prod_scal(cp, *cyl.direction);
	if (prod >= -tmp && prod <= tmp)
	{
		return (0);
	}
	return (1);
}

double	get_a_cyl(t_vector dir, t_cylinder cyl)
{
	double	a;

	a = prod_scal(dir, *cyl.direction);
	a = -1 * a * a;
	a += 1;
	return (a);
}

double	get_b_cyl(t_vector dir, t_cylinder cyl, t_vector ca)
{
	double	b;

	b = prod_scal(ca, dir);
	b -= prod_scal(ca, *cyl.direction) * prod_scal(dir, *cyl.direction);
	b = b * 2;
	return (b);
}

double	get_c_cyl(t_cylinder cyl, t_vector ca)
{
	double	c;

	c = norm_vec(ca) * norm_vec(ca);
	c -= prod_scal(ca, *cyl.direction) * prod_scal(ca, *cyl.direction);
	c -= cyl.diameter * cyl.diameter;
	return (c);
}
