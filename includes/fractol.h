/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:12:25 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/07 22:07:51 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

#define _GNU_C_SOURCE
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define WINDOW_NAME "Window"
# define ZOOM_SPEED 1.05
# define MAX_ITER 100

typedef struct	s_camera
{
	float left;
	float right;
	float top;
	float bottom;
	float s;
}				t_camera;

typedef struct	s_mouse
{
	float x;
	float y;
}				t_mouse;

typedef struct	s_fractal
{
	unsigned	color;
	int			effect_b;
	int			frac;
}				t_fractal;

typedef struct	s_image
{
	void	*image;
	void	*ptr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_world
{
	void		*mlx;
	void		*window;
	t_camera	cam;
	t_fractal	frac;
	t_mouse		mouse;
	t_image		image;
}				t_world;


void	init_image(t_world *w);
void	img_pixel_put(t_image *img, int x, int y, int color);
void	clear_image(t_world *w);

void	key_menu(void);
void	usage(void);

int		key_pressed_hook(int key, t_world *w);
int		mouse_moved_hook(int x, int y, t_world *w);
int		mouse_wheel_hook(int button, int x, int y, t_world *w);

void	draw(t_world *w);

float	ft_fmap(float input, float input_start, float input_end, float output_start, float output_end);
void	set_frac(t_world *w, float *ca, float *cb);
int		set_board_type(t_world *w, char *board);

#endif
