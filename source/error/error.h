/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 04:49:46 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 19:07:46 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef struct s_context	t_context;

// Print error_msg to std_err
int							print_error(char *error_msg);
// Print error_msg to std_err and exit the program
void						print_exit_error(char *error_msg);
void						lexer_error(t_context *context);

#endif
