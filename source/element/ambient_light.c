/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:29:33 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/23 03:03:29 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_ambient_light(char **data, t_element *element)
{
	t_ambient_light	ambient_light;

	if (*data[1] == '0' || *data[1] == '1')
		ambient_light.intensity = ft_atof(data[1]);
	if (ambient_light.intensity < 0 || ambient_light.intensity > 1)
		print_exit_error("Ambient light intensity must be between 0 and 1");
	element->u_element.ambient_light = ambient_light;
}