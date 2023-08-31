# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 13:13:45 by pabastid          #+#    #+#              #
#    Updated: 2023/08/30 21:03:39 by pabastid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE			=	make --no-print-directory
NAME			=	MATIAS

MAKEFILE			=	Makefile

SRCS			=	sources/init_window.c sources/main.c sources/init_window_image.c

OBJS			=	$(SRCS:.c=.o)

RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I includes/mlx

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
