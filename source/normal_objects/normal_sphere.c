/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:51:05 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/11 15:55:24 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vector	get_normal_sphere(t_vector intersection, t_vector center)
{
	t_vector	res;

	res = diff_vec(intersection, center);
	res = prod_nb_vec(1 / norm_vec(res), res);
	return (res);
}
