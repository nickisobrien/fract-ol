/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:12:25 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/09 03:24:41 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>

# define WIDTH 770
# define HEIGHT 770
# define WINDOW_NAME "Window"
# define ZOOM_SPEED 1.05
# define STARTING_ITER 100
# define COLORA 5000000
# define COLORB 120000
# define LASTCOLOR 0xffffff
# define MOVE_SPEED 0.05
# define THREADS 4
# define MOVE_FACTOR 700

typedef struct	s_camera
{
	long double	x;
	long double	y;
	long double	s;
}				t_camera;

typedef struct	s_mouse
{
	long double	x;
	long double	y;
	int			active;
}				t_mouse;

typedef struct	s_fractal
{
	unsigned	color;
	int			eb;
	int			frac;
}				t_fractal;

typedef struct	s_image
{
	void		*image;
	void		*ptr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_world
{
	void		*mlx;
	void		*window;
	long double	max_iter;
	t_camera	cam;
	t_fractal	frac;
	t_mouse		mouse;
	t_image		image;
}				t_world;

typedef struct	s_data
{
	int			job;
	t_world		*w;
}				t_data;

void			init_image(t_world *w);
void			img_pixel_put(t_image *img, int x, int y, int color);
void			clear_image(t_image *image);

void			key_menu(void);
void			usage(void);

int				key_pressed_hook(int key, t_world *w);
int				mouse_moved_hook(int x, int y, t_world *w);
int				mouse_wheel_hook(int button, int x, int y, t_world *w);

void			draw(t_world *w);

void			set_color(t_world *w, int color, int a, int b);
void			set_frac(t_world *w, long double *ca, long double *cb);
int				set_board_type(t_world *w, char *board);
void			error(void);
void			reset(t_world *w);

#endif
