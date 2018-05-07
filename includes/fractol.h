/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:12:25 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/16 18:23:07 by nobrien          ###   ########.fr       */
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
	int			effect;
	int			frac;
}				t_fractal;

typedef struct	s_world
{
	void		*mlx;
	void		*window;
	t_camera	cam;
	t_fractal	frac;
	t_mouse		mouse;
}				t_world;

#endif
