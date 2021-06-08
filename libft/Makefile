# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 15:43:59 by tmkrtchy          #+#    #+#              #
#    Updated: 2021/01/30 16:31:19 by tmkrtchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CFLAGS		= -Wall -Wextra -Werror -I.
RM			= rm -f

SRCS	=	ft_toupper.c ft_tolower.c ft_substr.c ft_strtrim.c ft_strrchr.c \
			ft_strnstr.c ft_strncmp.c ft_strmapi.c ft_strlen.c ft_strlcpy.c \
			ft_strlcat.c ft_strjoin.c ft_strdup.c ft_strchr.c ft_putstr_fd.c \
			ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_memset.c \
			ft_memmove.c ft_memcpy.c ft_memcmp.c ft_memchr.c ft_memccpy.c \
			ft_lstsize.c ft_lstnew.c ft_lstmap.c ft_lstlast.c ft_lstiter.c \
			ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c \
			ft_itoa.c ft_isprint.c ft_isdigit.c ft_isascii.c ft_isalpha.c \
			ft_isalnum.c ft_calloc.c ft_bzero.c ft_atoi.c ft_split.c ft_strcmp.c \
			ft_strdel.c ft_putchar.c ft_putnbr.c ft_strsplit.c ft_wordmalloc.c \
			ft_countword.c ft_rewriting.c ft_isspace.c ft_intcpy.c ft_nbrlen.c

OBJ			= $(SRCS:.c=.o)

BONUS		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS	=	$(BONUS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJ)
			@ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJ) $(BONUS_OBJS)

.PHONY:		all clean fclean re bonus
