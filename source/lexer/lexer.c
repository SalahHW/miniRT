/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:43:37 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/22 02:22:01 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	run_lexer(char *file_path)
{
	t_rt_file		rt_file;
	t_element_list	*element_list;

	rt_file.file_name = file_path;
	open_rt_file(&rt_file);
	element_list = init_element_list();
	if (!element_list)
	{
		//close_rt_file(&rt_file);
		print_exit_error("Unable to allocate memory for element list");
	}
	extract_rt_file_data(&rt_file, element_list);
}
