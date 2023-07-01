# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graiolo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 16:18:51 by graiolo           #+#    #+#              #
#    Updated: 2023/07/01 18:52:29 by graiolo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol

SRCS_DIR		=	src/

ODIR			=	obj/

INCLUDES		=	includes/

SRCS_F			=	ft_main.c\
					ft_check_name_fractal.c\
					ft_init_mlx.c \
					ft_create_image.c \
					ft_zoom_hook.c\
					ft_key_hook.c\
					ft_operation_fractal.c\
					ft_fractal_mandelbrot.c \
					ft_fractal_julia_set.c\
					ft_tricon.c\
					ft_msg_error.c\
					ft_printf_info.c\
					ft_destroy_fractol.c

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))
OFILE			=	$(addprefix $(ODIR), $(OBJS))

OBJS			=	$(SRCS_F:.c=.o)

CC				=	cc

CC_FLAGS		= 	-Wall -Wextra -Werror -g -O3

RM				=	rm -f

RMD				=	rm -rf

$(ODIR)%.o : $(SRCS_DIR)%.c
				$(CC) $(CC_FLAGS) -c $< -o $@ -I includes -I minilibx-linux -I libft/include

$(NAME):		$(OFILE)
				make -sC libft all
				make -sC minilibx-linux all
				$(CC) $(CC_FLAGS) -lpthread $(OFILE) -o $(NAME) -L minilibx-linux -lmlx -lXext -lX11 -lm libft/archive/libft.a

all:			$(NAME)

clean:
				make -sC minilibx-linux clean
				make -sC libft clean
				$(RM) $(OFILE)

clean2:
				make -sC minilibx-linux clean
				make -sC libft fclean
				$(RM) $(OFILE)

fclean:			clean2
				$(RM) $(NAME)

bonus:			all

norm:			
				norminette includes/ libft/ src/

push:
				git add *
				git commit -m "auto push"
				git push

re:				fclean all

.PHONY:			all clean fclean norm re
.SILENT:
