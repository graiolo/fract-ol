# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graiolo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 16:19:35 by graiolo           #+#    #+#              #
#    Updated: 2023/01/03 16:19:37 by graiolo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = new_libft

all: $(NAME)

$(NAME): dir
	make -C libft
	make -C ft_printf
	make -C get_next_line

clean:
	make -C libft clean
	make -C ft_printf clean
	make -C get_next_line clean

fclean: clean
	make -C libft fclean
	make -C ft_printf fclean
	make -C get_next_line fclean
	rm -df archive

bonus: dir
	make -C libft bonus
	make -C ft_printf bonus
	make -C get_next_line bonus

norm:	
	norminette | sed -E 's/.*\/(.*)/\1/'

dir:
	if [ ! -d "archive" ]; then \
		mkdir archive; \
	fi

re : fclean all

.PHONY: all clean fclean dir
.SILENT:


