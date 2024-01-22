/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:43:37 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/22 02:15:16 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	run_lexer(char *file_path)
{
	t_rt_file		rt_file;
	t_element_list	*t_element_list;

	rt_file.file_name = file_path;
	open_rt_file(&rt_file);
	t_element_list = extract_rt_file_data(&rt_file);
}
