/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:54:55 by pabastid          #+#    #+#             */
/*   Updated: 2023/09/15 12:21:35 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	julia_00(float cx, float cy)
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
		temp = zx * zx - zy * zy + -0.569;
		zy = 2 * zx * zy + -0.483;
		zx = temp;
		i++;
	}
	return (i);
}

int	julia_01(float cx, float cy)
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
		temp = zx * zx - zy * zy + -0.758;
		zy = 2 * zx * zy + 0.132;
		zx = temp;
		i++;
	}
	return (i);
}

int	julia_02(float cx, float cy)
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
		temp = zx * zx - zy * zy + 0.381;
		zy = 2 * zx * zy + 0.107;
		zx = temp;
		i++;
	}
	return (i);
}
