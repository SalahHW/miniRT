/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 04:49:46 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/27 03:59:27 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// Print error_msg to std_err
void    print_error(char *error_msg);
// Print error_msg to std_err and exit the program
void    print_exit_error(char *error_msg);

#endif
