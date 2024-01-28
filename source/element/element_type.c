/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:11:37 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/27 07:12:06 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_element_identifier	get_element_type(char *str)
{
	t_element_identifier	type;

	if (ft_strncmp(str, "A", 2) == 0)
		type = ambient_light;
	else if (ft_strncmp(str, "C", 2) == 0)
		type = camera;
	else if (ft_strncmp(str, "L", 2) == 0)
		type = light;
	else if (ft_strncmp(str, "sp", 3) == 0)
		type = sphere;
	else if (ft_strncmp(str, "pl", 3) == 0)
		type = plane;
	else if (ft_strncmp(str, "cy", 3) == 0)
		type = cylinder;
	return (type);
}