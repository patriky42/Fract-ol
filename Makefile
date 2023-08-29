# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 13:13:45 by pabastid          #+#    #+#              #
#    Updated: 2023/08/29 17:31:58 by pabastid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE			=	make --no-print-directory
NAME			=	MATIAS

MAKEFILE			=	Makefile

SRCS			=	init_window.c

OBJS			=	$(SRCS:.c=.o)

RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I mlx

%.o: %.c  $(MAKEFILE)
	@$(CC) $(CFLAGS) -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "Removed all \'.o\' files\n"

fclean:
	@$(MAKE) clean
	@$(RM) $(NAME)
re:
	@$(MAKE) fclean
	@$(MAKE)
	
.PHONY: all clean fclean re
