/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:02:42 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/07 15:09:14 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	usage(void)
{
	ft_printf("Usage: ./fractol [fractal]");
	ft_printf("Fracals:\n(m)andelbrot\n(j)ulia\n");
}

void	key_menu(void)
{
	ft_printf("Move: 'W', 'A', 'S', 'D'\n");
	ft_printf("Zoom: (in)'E', (out)'Q'\n");
	ft_printf("Color: 'C'\n");
	ft_printf("Mode: (normal)'Z', (psychedelic)'X'\n");
	ft_printf("Fracal:\n(mandelbrot)'1'\n(julia)'2'\n");
}