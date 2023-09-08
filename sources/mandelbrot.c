/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:59:53 by pabastid          #+#    #+#             */
/*   Updated: 2023/09/08 15:25:24 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

// esta funcion solo comprueba si un pixel esta en mandelbrot o no
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
	// las iteraciones lleguen a 500 y los valores no vayan al infinito.
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = temp;
		i++;
	}
	return (i);
}
