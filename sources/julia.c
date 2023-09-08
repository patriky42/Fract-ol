/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:54:55 by pabastid          #+#    #+#             */
/*   Updated: 2023/09/08 17:40:57 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

// esta funcion solo comprueba si un pixel esta en mandelbrot o no
int	julia(float cx, float cy)
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
		temp = zx * zx - zy * zy + -0.569;
		zy = 2 * zx * zy + -0.483;
		zx = temp;
		i++;
	}
	return (i);
}
