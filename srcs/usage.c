/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:02:42 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 21:17:09 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	usage(void)
{
	ft_printf("Usage: ./fractol [fractal]\n");
	ft_printf("Fractals:\n'1': Mandelbrot\n'2': Julia\n'3': Burningship\n");
	exit(-1);
}

void	key_menu(void)
{
	ft_printf("Move: 'W' 'A' 'S' 'D'\n\n");
	ft_printf("Zoom:\n'E' +\n'Q' -\nMOUSE WHEEL\n\n");
	ft_printf("Color: 'C'\n\n");
	ft_printf("Mode:\n'Z' Normal 1\n'X' Normal 2\n\n");
	ft_printf("Toggle Mouse Movement: Click\n\n");
	ft_printf("Quality:\n'V' Increase\n'B', Decrease\n\n");
	ft_printf("Fractal:\n'1' Mandelbrot\n'2' Julia\n'3' Burningship\n\n");
	ft_printf("Reset: 'R'\n\n");
	ft_printf("Exit: 'esc'\n");
}
