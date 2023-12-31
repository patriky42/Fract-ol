/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:06:24 by pabastid          #+#    #+#             */
/*   Updated: 2023/09/15 13:06:03 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
}

int	check_arguments(int argc, char **argv)
{
	if (argc == 2 && ft_strlen(argv[1]) == 1
		&& (argv[1][0] == '1' || argv[1][0] == '2'
			|| argv[1][0] == '3' || argv[1][0] == '4'))
		return (1);
	ft_putstr("Anda, escriba '1' si lo que quiere es imprimir Mandelbrot\n");
	ft_putstr("O escriba '2' si quiere imprimir el modelo 1 de Julia\n");
	ft_putstr("O escriba '3' si quería imprimir el modelo 2 de Julia\n");
	ft_putstr("O escriba '4' si quería imprimir el modelo 3 de Julia\n");
	return (0);
}
