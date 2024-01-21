/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:25:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/21 07:41:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	open_rt_file(t_rt_file *rt_file)
{
	rt_file->fd = open(rt_file->file_name, O_RDONLY);
	if (rt_file->fd < 0)
		print_exit_error("Can't open file");
}

t_element_list	*extract_rt_file_data(t_rt_file *rt_file)
{
	char			*line;
	t_element_list	*element_list;
	t_element		*element;

	element_list = init_element_list();
	line = get_next_line(rt_file->fd);
	while (line)
	{
		if (!is_empty_line(line))
			element = get_element(line, element_list);
		if (element)
			add_element(element_list, element);
		free(line);
		line = get_next_line(rt_file->fd);
	}
	return (element_list);
}
