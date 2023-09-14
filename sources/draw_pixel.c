/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:01:34 by pabastid          #+#    #+#             */
/*   Updated: 2023/09/14 11:44:18 by pabastid         ###   ########.fr       */
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

void	draw_window(t_mlx *luciano)
{
	int		x;
	int		y;
	float	cx;
	float	cy;

	x = 0;
	y = 0;
	while (x < 1920)
	{
		while (y < 1080)
		{
			cx = ((x * 3.0 / 1920.0) - 2.0) * luciano->zoom;
			cy = ((y * 2.0 / 1080.0) - 1.0) * luciano->zoom;
			my_mlx_pixel_put(&luciano->image, x, y, colors(luciano->function(cx,
						cy)));
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(luciano->mlx, luciano->mlx_window,
		luciano->image.img, 0, 0);
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
