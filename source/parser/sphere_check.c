/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:09:13 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 19:14:27 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	check_sphere(t_element *element)
{
	t_sphere	sphere;

	sphere = element->u_element.sphere;
	if (check_color(sphere.color) == FAILURE)
		return (print_error("Sphere color is out of range [0 - 255]"));
	if (check_size(sphere.diameter) == FAILURE)
		return (print_error("Sphere diameter is out of range [0 - 999]"));
	return (SUCCESS);
}
