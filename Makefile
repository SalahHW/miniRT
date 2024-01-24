# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 04:27:06 by sbouheni          #+#    #+#              #
#    Updated: 2024/01/21 08:37:53 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	miniRT

CC						=	gcc
CFLAGS					=	-Wall -Wextra -g3 -fsanitize=address
DEBUGFLAGS				=	-g3

LIBFT					=	./include/libft/libft.a
MLX						=	./include/minilibx-linux/

SRCS					=	source/main.c									\
							source/error/error.c							\
							source/lexer/lexer.c							\
							source/lexer/file_reading.c						\
							source/lexer/file_reading_utils.c				\
							source/lexer/tokenizer.c						\
							source/element/element.c						\
							source/element/element_list.c					\
							source/element/element_process.c				\
							source/element/ambient_light.c					\
							source/element/camera.c							\
							source/element/light.c							\
							source/element/sphere.c							\
							source/element/plane.c							\
							source/element/cylinder.c						\
							source/utils/ft_atof.c							\

OBJS					=	$(SRCS:.c=.o)

all						:	$(NAME)

$(NAME)					:	$(OBJS)
							make -C ./include/libft
							make -C ./include/minilibx-linux
							$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX) -lmlx -lXext -lX11 -o $(NAME)

debug					:	$(OBJS)
							make -C ./include/libft
							make -C ./include/minilibx-linux
							$(CC) $(DEBUGFLAGS) $(OBJS) $(LIBFT) -L$(MLX) -lmlx -lXext -lX11 -o $(NAME)-debug

clean					:
							rm -f $(OBJS)
							make clean -C ./include/libft
							make clean -C ./include/minilibx-linux

fclean					:	clean
							rm -f $(NAME)

re						:	fclean all

.PHONY					:	all clean fclean re
