# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 04:27:06 by sbouheni          #+#    #+#              #
#    Updated: 2024/01/15 07:21:25 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	miniRT

CC						=	gcc
CFLAGS					=	-Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT					=	./include/libft/libft.a
MLX						=	./include/minilibx-linux/

SRCS					=	source/main.c									\
							source/error/error.c							\
							source/lexer/lexer.c							\
							source/lexer/file_reading.c						\
							source/lexer/file_reading_utils.c				\
							source/lexer/tokenizer.c						\
							source/lexer/element_list.c						\

OBJS					=	$(SRCS:.c=.o)

all						:	$(NAME)

$(NAME)					:	$(OBJS)
							make -C ./include/libft
							$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX) -lmlx -lXext -lX11 -o $(NAME)

clean					:
							rm -f $(OBJS)
							make clean -C ./include/libft

fclean					:	clean
							rm -f $(NAME)

re						:	fclean all

.PHONY					:	all clean fclean re
