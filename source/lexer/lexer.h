/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 01:04:46 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/20 03:36:02 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_element		t_element;
typedef struct s_element_list	t_element_list;

typedef struct s_rt_file
{
	char						*file_name;
	int							fd;
}								t_rt_file;

// Execute lexer process
void							run_lexer(char *file_path);
// Open file and return file descriptor
void							open_rt_file(t_rt_file *rt_file);
// Read file and return data
t_element_list					*extract_rt_file_data(t_rt_file *rt_file);

// ========== FILE_READING ===========//
// Init a NULL list of element
t_element_list					*init_element_list(void);
void							add_element(t_element_list *list,
									t_element *element);

// ========== FILE READING UTILS ========== //
// Check if line is empty
int								is_empty_line(char *line);

void							process_line(char *line);

#endif
