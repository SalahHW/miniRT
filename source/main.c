/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 04:32:04 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/28 05:06:30 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	is_rt_file(char *file_name)
{
	char	*extension;

	extension = ft_strchr(file_name, '.');
	if (extension == NULL)
		return (FAILURE);
	if (ft_strncmp(extension, ".rt", 4))
		return (FAILURE);
	return (SUCCESS);
}

static void	check_args(int argc, char **argv)
{
	if (argc < 2)
		print_exit_error("No file specified");
	else if (argc > 3)
		print_exit_error("Too many arguments");
	if (is_rt_file(argv[1]) == FAILURE)
		print_exit_error("File is not a .rt extension");
}

int	main(int argc, char **argv)
{
	t_context	*context;
	
	check_args(argc, argv);
	context = init_context();
	context->rt_file->file_path = argv[1];
	if (run_lexer(context) == FAILURE)
		lexer_error(context);
	return (0);
}
