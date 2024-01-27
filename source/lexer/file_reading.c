/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:25:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/27 06:31:21 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	open_rt_file(t_rt_file *rt_file)
{
	rt_file->fd = open(rt_file->file_path, O_RDONLY);
	if (rt_file->fd < 0)
	{
		print_error("Unable to open file");
		return (FAILURE);
	}
}

int	extract_rt_file_data(t_context *context)
{
	context->rt_file->current_line = get_next_line(context->rt_file->fd);
	while (context->rt_file->current_line)
	{
		if (!is_empty_line(context->rt_file->current_line))
		{
			if (extract_element(context) == FAILURE)
				return (FAILURE);
		}
		free(context->rt_file->current_line);
		context->rt_file->current_line = get_next_line(context->rt_file->current_line);
	}
	free(context->rt_file->current_line);
	return (SUCCESS);
}
