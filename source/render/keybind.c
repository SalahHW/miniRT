/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:10:36 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:14:42 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	deal_key(int key, t_context *context)
{
	if (key == 65307)
		close_window(context);
	return (0);
}
