/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cyl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:50:48 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/22 18:16:47 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vector	get_normal_cyl(t_vector intersection, t_vector axis,
		t_vector center)
{
	t_vector	res;
	double		scal;

	res = diff_vec(intersection, center);
	scal = prod_scal(res, axis);
	res = diff_vec(res, prod_nb_vec(scal, axis));
	res = prod_nb_vec(1 / norm_vec(res), res);
	return (res);
}
