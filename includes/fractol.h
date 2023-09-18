/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:36:16 by pabastid          #+#    #+#             */
/*   Updated: 2023/09/15 12:50:22 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define W 1400
# define H 800

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_mlx
{
	int		(*function)(float, float);
	void	*mlx;
	void	*mlx_window;
	t_data	image;
	float	zoom;
}			t_mlx;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_window(t_mlx *luciano);
int			mandelbrot(float cx, float cy);
int			julia_00(float cx, float cy);
int			julia_01(float cx, float cy);
int			julia_02(float cx, float cy);
int			colors(int i);
int			mousepress(int button, int x, int y, t_mlx *mafalda);
int			esc(int key, void *param);
int			ft_exit(void *param);
size_t		ft_strlen(const char *s);
void		ft_putstr(char *str);
int			check_arguments(int argc, char **argv);

#endif
