# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graiolo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 16:19:41 by graiolo           #+#    #+#              #
#    Updated: 2023/01/03 16:19:43 by graiolo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= ../archive/libft.a

IDIR 		=../include

CFLAG 		= -Wall -Werror -Wextra -I $(IDIR)

CC 		= gcc $(CFLAG) -c

RM 		= rm -f

DRM		= rm -fr

LIB 		= ar rc $(NAME)

DIR 		= src/

DIR_EXTRA	= src_extra/

DIR_BONUS 	= src_bonus/

ODIR 		= obj/

ODIR_EXTRA	= obj_extra/

ODIR_BONUS	= obj_bonus/


SRC_FILES 	= 	ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_isspace.c\
			ft_strlen.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memccpy.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_memcpy_rvs.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c

SRC_FILES_EXTRA =	ft_strncpy.c\
			ft_strcpy.c\
			ft_strcat.c\
			ft_uitoa.c\
			ft_min.c\
			ft_max.c\
			ft_atof.c

SRC_FILES_BONUS =	ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c


$(ODIR)%.o : $(DIR)%.c
	$(CC) $(CFLAG) $< -o $@

$(ODIR_EXTRA)%.o : $(DIR_EXTRA)%.c
	$(CC) $(CFLAG) $< -o $@

$(ODIR_BONUS)%.o : $(DIR_BONUS)%.c
	$(CC) $(CFLAG) $< -o $@



OBG = $(SRC_FILES:.c=.o)

OBG_EXTRA = $(SRC_FILES_EXTRA:.c=.o)

OBG_BONUS = $(SRC_FILES_BONUS:.c=.o)


OFILE  = $(addprefix $(ODIR), $(OBG))

OFILE_EXTRA  = $(addprefix $(ODIR_EXTRA), $(OBG_EXTRA))

OFILE_BONUS  = $(addprefix $(ODIR_BONUS), $(OBG_BONUS))


DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
RED = \033[0;91m
CIANO = \033[0;96m


all: $(NAME)

$(NAME): dir $(OFILE) $(OFILE_EXTRA)
	@$(LIB) $(OFILE_EXTRA)
	@echo "$(GREEN)libft.a extra file compilati correttamente!$(DEF_COLOR)"
	@$(LIB) $(OFILE) 
	@echo "$(GREEN)libft.a compilata con successo!$(DEF_COLOR)"


clean:
	@$(RM) $(OFILE) $(OFILE_EXTRA) $(OFILE_BONUS)
	@$(DRM) $(ODIR) $(ODIR_EXTRA) $(ODIR_BONUS)
	@echo "$(CIANO)file .obj di libft eliminati con successo!$(DEF_COLOR)"

clean2:
	@$(RM) $(OFILE) $(OFILE_EXTRA) $(OFILE_BONUS)
	@$(DRM) $(ODIR) $(ODIR_EXTRA) $(ODIR_BONUS)

fclean: clean2
	@$(RM) $(NAME)
	@echo "$(RED)libft.a rimossa con successo!$(DEF_COLOR)"

re: fclean all 

bonus: dir_bonus $(OFILE) $(OFILE_EXTRA) $(OFILE_BONUS)
	@$(LIB) $(OFILE) $(OFILE_EXTRA) $(OFILE_BONUS)
	@echo "$(GREEN)bonus libft.a compilata con successo!$(DEF_COLOR)"

dir:
	if [ ! -d "$(ODIR)" ]; then \
		mkdir $(ODIR); \
	fi
	if [ ! -d "$(ODIR_EXTRA)" ]; then \
		mkdir $(ODIR_EXTRA); \
	fi

dir_bonus: dir
	if [ ! -d "$(ODIR_BONUS)" ]; then \
		mkdir $(ODIR_BONUS); \
	fi

.PHONY: all clean fclean bonus


