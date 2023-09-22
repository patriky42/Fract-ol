/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:01:34 by pabastid          #+#    #+#             */
/*   Updated: 2023/09/22 11:05:27 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_window(t_mlx *mlx) //esta funcion rellena cada pixel de un color
{
	int		x;
	int		y;
	float	cx;
	float	cy;

	x = 0;
	y = 0;
	while (x < W)
	{
		while (y < H)
		{
			cx = ((x * 3.0 / (float)W) - 2.0) * mlx->zoom; //mlx.zoom en el main = 1; porque aqui queremos que si no hay zoom haga el calculo entre parentesis.
			cy = ((y * 2.0 / (float)H) - 1.0) * mlx->zoom;
			my_mlx_pixel_put(&mlx->image, x, y, colors(mlx->function(cx, cy)));
			y++;
			//Aqui usamos mandelbrot para en funcion del valor i que devuelva pintamos del color segun colors.
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window,
		mlx->image.img, 0, 0);
}

int	colors(int i)
{
	if (i < 15)
		return (0xA9DFBF);
	if (i < 30)
		return (0x7DCEA0);
	if (i < 45)
		return (0x52BE80);
	if (i < 60)
		return (0x27AE60);
	if (i < 75)
		return (0x229954);
	if (i < 90)
		return (0x1E8449);
	if (i < 105)
		return (0x196F3D);
	if (i < 120)
		return (0x145A32);
	if (i < 150)
		return (0x0B5345);
	if (i == 500)
		return (0xF4D03F);
	return (0xC0392B);
}
