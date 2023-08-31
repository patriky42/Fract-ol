/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:52:26 by pabastid          #+#    #+#             */
/*   Updated: 2023/08/30 20:55:22 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "1, 2, 3, probando!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i < 1920)
	{
		while (j < 1080)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
