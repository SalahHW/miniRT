/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 01:04:46 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/27 07:00:15 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_context		t_context;
typedef struct s_element		t_element;
typedef struct s_element_list	t_element_list;

typedef struct s_rt_file
{
	char						*file_path;
	int							fd;
	char						*current_line;
}								t_rt_file;

// Execute lexer process
int								run_lexer(t_context *context);
// Open file and return file descriptor
int								open_rt_file(t_rt_file *rt_file);
// Read file and fill element_list
int								extract_rt_file_data(t_context *context);
// Check if line is empty
int								is_empty_line(char *line);

#endif
