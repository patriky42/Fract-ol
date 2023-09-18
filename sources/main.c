/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:52:26 by pabastid          #+#    #+#             */
/*   Updated: 2023/09/15 12:52:31 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

void	get_option(t_mlx *mlx, char **argv)
{
	if (argv[1][0] == '1')
	{
		mlx->function = mandelbrot;
	}
	else if (argv[1][0] == '2')
	{
		mlx->function = julia_00;
	}
	else if (argv[1][0] == '3')
	{
		mlx->function = julia_01;
	}
	else if (argv[1][0] == '4')
	{
		mlx->function = julia_02;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (check_arguments(argc, argv) != 1)
		exit(1);
	get_option(&mlx, argv);
	mlx.zoom = 1;
	mlx.mlx = mlx_init();
	mlx.mlx_window = mlx_new_window(mlx.mlx, W, H,
			"Aquí está tu fractol elegido!");
	mlx.image.img = mlx_new_image(mlx.mlx, W, H);
	mlx.image.addr = mlx_get_data_addr(mlx.image.img, &mlx.image.bits_per_pixel,
			&mlx.image.line_length, &mlx.image.endian);
	mlx_hook(mlx.mlx_window, 2, 0, esc, NULL);
	mlx_hook(mlx.mlx_window, 17, 0, ft_exit, NULL);
	mlx_hook(mlx.mlx_window, 4, 0, mousepress, &mlx);
	draw_window(&mlx);
	mlx_loop(mlx.mlx);
}
