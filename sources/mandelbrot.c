/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:59:53 by pabastid          #+#    #+#             */
/*   Updated: 2023/09/14 11:39:58 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	mandelbrot(float cx, float cy)
{
	int		i;
	float	zx;
	float	zy;
	float	temp;

	i = 0;
	zx = cx;
	zy = cy;
	while (i < 500 && (zx * zx + zy * zy) <= 4)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = temp;
		i++;
	}
	return (i);
}
