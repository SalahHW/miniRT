/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:03:30 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/09 00:18:51 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int is_rt_file(char *file_name)
{
	char *extension;

	extension = ft_strchr(file_name, '.');
	if (extension == NULL)
		return (0);
	if (ft_strncmp(extension, ".rt", 4) == 0)
		return (1);
	else
		return (0);
}

void	parse_args(int argc, char **argv)
{
	if (argc < 2)
		print_exit_error("Error\nNo file specified");
	else if (argc > 3)
		print_exit_error("Error\nToo many arguments");
	if (!is_rt_file(argv[1]))
		print_exit_error("Error\nFile is not a .rt extension");
}

void	parse_rt_file(char *file_name)
{
	ft_printf("Parsing file %s\n", file_name);
}
