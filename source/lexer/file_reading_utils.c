/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:15:51 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/13 09:16:59 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_white_space(line[i]) && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char *skip_white_space(char *str)
{
	while (*str && is_white_space(*str))
		str++;
	return (str);
}

char *skip_non_white_space(char *str)
{
	while (*str && !is_white_space(*str))
		str++;
	return (str);
}