# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 04:27:06 by sbouheni          #+#    #+#              #
#    Updated: 2024/03/20 18:45:33 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	miniRT

CC						=	gcc
CFLAGS					=	-g3 -Wall -Wextra #-fsanitize=address #-Werror
DEBUGFLAGS				=	-g3

LIBFT					=	./include/libft/libft.a
MLX						=	./include/minilibx-linux/

SRCS					=	source/main.c									\
							source/error/error.c							\
							source/error/lexer_error.c						\
							source/error/parser_error.c						\
							source/ressource/context.c						\
							source/ressource/quit_program.c 				\
							source/decimal/decimal.c						\
							source/decimal/decimal_compatibility.c			\
							source/lexer/lexer.c							\
							source/lexer/file_reading.c						\
							source/lexer/file_reading_utils.c				\
							source/element/vector.c							\
							source/element/color.c							\
							source/element/element.c						\
							source/element/element_extraction.c				\
							source/element/element_type.c					\
							source/element/element_list.c					\
							source/element/element_process.c				\
							source/element/ambient_light.c					\
							source/element/camera.c							\
							source/element/light.c							\
							source/element/sphere.c							\
							source/element/plane.c							\
							source/element/cylinder.c						\
							source/parser/parser.c							\
							source/parser/counter_check.c					\
							source/parser/vector_check.c					\
							source/parser/color_check.c						\
							source/parser/element_check.c					\
							source/parser/ambient_light_check.c				\
							source/parser/camera_check.c					\
							source/parser/light_check.c						\
							source/parser/sphere_check.c					\
							source/parser/plane_check.c						\
							source/parser/cylinder_check.c					\
							source/render/render.c							\
							source/render/session.c							\
							source/render/window.c							\
							source/render/keybind.c							\
							source/intersection/intersection.c				\
							source/intersection/intersection_plan.c			\
							source/intersection/init_vec.c					\
							source/intersection/init_vec_utils.c			\
							source/intersection/intersection_sphere.c		\
							source/intersection/intersection_cyl.c			\
							source/intersection/intersection_cyl_utils.c	\
							source/normal_objects/normal_cyl.c				\
							source/normal_objects/normal_plan.c				\
							source/normal_objects/normal_sphere.c			\
							source/light/light.c							\
							source/light/illuminated.c						\
							source/light/inter_cyl_bis.c					\
							source/light/inter_plan_bis.c					\
							source/light/inter_sphere_bis.c					\
							source/equation/tools_math.c					\
							source/equation/tools_math2.c					\
							source/utils/split_length.c						\

OBJS					=	$(SRCS:.c=.o)

all						:	$(NAME)

$(NAME)					:	$(OBJS)
							make -C ./include/libft
							make -C ./include/minilibx-linux
							$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX) -lmlx -lXext -lX11 -lm -o $(NAME)

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
