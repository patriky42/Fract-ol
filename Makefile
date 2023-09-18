# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 13:13:45 by pabastid          #+#    #+#              #
#    Updated: 2023/09/15 12:11:43 by pabastid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE			=	make --no-print-directory
NAME			=	fractol

MAKEFILE		=	Makefile

PUSH			=	sources/main.c $(SRCS)
SRCS			=	sources/draw_pixel.c sources/mandelbrot.c sources/hooks.c sources/julia.c sources/check_arguments.c
OBJS			=	$(PUSH:.c=.o)

RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I includes/mlx -I includes

%.o: %.c  $(MAKEFILE)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$< compiled!"

all:
	@$(MAKE) -C includes/mlx/
	@cp includes/mlx/libmlx.dylib .
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L includes/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\nFractol executable created!"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -C includes/mlx/
	@echo "Removed all \'.o\' files\n"

fclean:
	@$(MAKE) clean
	@$(RM) libmlx.dylib
	@$(RM) include/mlx/libmlx.dylib
	@$(RM) $(NAME)
re:
	@$(MAKE) fclean
	@$(MAKE)
	
.PHONY: all clean fclean re
