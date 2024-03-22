/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:25:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:17:24 by sbouheni         ###   ########.fr       */
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

static int	extract_line_data(t_context *context, char *current_line)
{
	char	**data;

	data = ft_split_white_space(current_line);
	if (!data)
		return (print_error("Unable to split data from file"));
	if (extract_element(context, data) == FAILURE)
	{
		p_free_splited_str(data);
		return (FAILURE);
	}
	p_free_splited_str(data);
	return (SUCCESS);
}

int	extract_rt_file_data(t_context *context)
{
	char	*current_line;
	int		error_occured;

	error_occured = 0;
	current_line = get_next_line(context->rt_file->fd);
	while (current_line)
	{
		if (!is_empty_line(current_line) && !error_occured)
		{
			if (extract_line_data(context, current_line) == FAILURE)
				error_occured = 1;
		}
		free(current_line);
		current_line = get_next_line(context->rt_file->fd);
	}
	if (error_occured)
		return (FAILURE);
	return (SUCCESS);
}

void	clear_file(t_rt_file *file)
{
	close(file->fd);
	free(file);
}
