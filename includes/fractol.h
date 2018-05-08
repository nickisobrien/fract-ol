/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:12:25 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 06:57:00 by nobrien          ###   ########.fr       */
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
# define MAX_ITER 300
# define COLORA 0
# define COLORB 12000000
# define LASTCOLOR 2000
# define MOVE_SPEED 0.05
# define THREADS 20

typedef struct	s_camera
{
	float		x;
	float		y;
	float		s;
}				t_camera;

typedef struct	s_mouse
{
	float		x;
	float		y;
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
	int			line;
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
void			set_frac(t_world *w, float *ca, float *cb);
int				set_board_type(t_world *w, char *board);
void			error(void);

#endif
