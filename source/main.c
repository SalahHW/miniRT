/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 04:32:04 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/09 00:56:33 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	is_rt_file(char *file_name)
{
	char	*extension;

	extension = ft_strchr(file_name, '.');
	if (extension == NULL)
		return (0);
	if (!ft_strncmp(extension, ".rt", 4))
		return (1);
	else
		return (0);
}

static void	parse_args(int argc, char **argv)
{
	if (argc < 2)
		print_exit_error("Error\nNo file specified");
	else if (argc > 3)
		print_exit_error("Error\nToo many arguments");
	if (!is_rt_file(argv[1]))
		print_exit_error("Error\nFile is not a .rt extension");
}

int	main(int argc, char **argv)
{
	parse_args(argc, argv);
	ft_printf("miniRT exited successfully\n");
	return (0);
}
