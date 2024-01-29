/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:25:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/29 06:01:53 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_rt_file	*open_rt_file(char *file_path)
{
	t_rt_file	*file;

	file = malloc(sizeof(t_rt_file));
	if (!file)
	{
		print_error("Unable to allocate memory for rt file");
		return (NULL);
	}
	file->fd = open(file_path, O_RDONLY);
	if (file->fd < 0)
	{
		print_error("Unable to open file");
		free(file);
		return (NULL);
	}
	return (file);
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
		context->rt_file->current_line = get_next_line(context->rt_file->fd);
	}
	return (SUCCESS);
}

void	clear_file(t_rt_file *file)
{
	close(file->fd);
	free(file);
}
