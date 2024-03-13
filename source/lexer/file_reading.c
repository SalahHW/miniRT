/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:25:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/13 21:07:43 by sbouheni         ###   ########.fr       */
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
	char	*current_line;
	char	**data;

	current_line = get_next_line(context->rt_file->fd);
	while (current_line)
	{
		if (!is_empty_line(current_line))
		{
			data = ft_split_white_space(current_line);
			if (!data)
			{
				free(current_line); // Libérer la ligne actuelle en cas d'erreur
				return (print_error("Unable to split data from file"));
			}
			if (extract_element(context, data) == FAILURE)
			{
				free(current_line);
				p_free_splited_str(data); // Libération des données splitées
				return (FAILURE);
			}
			p_free_splited_str(data); // Libération des données splitées
		}
		free(current_line); // Libération de la ligne actuelle à chaque fin de boucle
		current_line = get_next_line(context->rt_file->fd);
	}
	return (SUCCESS);
}

void	clear_file(t_rt_file *file)
{
	close(file->fd);
	free(file);
}
