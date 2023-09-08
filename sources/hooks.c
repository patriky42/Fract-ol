/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:06:05 by pabastid          #+#    #+#             */
/*   Updated: 2023/09/08 15:43:43 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	esc(int key, void *param)
{
	(void)*param;
	if (key == 53)
		exit(1);
	return (0);
}

int	ft_exit(void *param)
{
	(void)*param;
	exit(1);
}

int	mousepress(int button, int x, int y, t_mlx *mafalda)
{
	(void)x;
	(void)y;
	if (button != 4 && button != 5)
		return (0);
	if (button == 4)
		mafalda->zoom /= 0.5;
	if (button == 5)
		mafalda->zoom *= 0.5;
	draw_window(mafalda);
	return (0);
}
