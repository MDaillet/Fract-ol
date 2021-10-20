/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:58:15 by mdaillet          #+#    #+#             */
/*   Updated: 2021/07/07 16:57:53 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_put_string(t_fract *s)
{
	mlx_string_put(s->mlx, s->win, 10, 15, 0xCCCCCC, "Quit = ESC");
	mlx_string_put(s->mlx, s->win, 10, 35, 0xCCCCCC, "Psy mode = 1 or 2");
	mlx_string_put(s->mlx, s->win, 10, 55, 0xCCCCCC, "Pink mode = 3");
	mlx_string_put(s->mlx, s->win, 10, 75, 0xCCCCCC, "Blue mode = 4");
	mlx_string_put(s->mlx, s->win, 10, 95,
		0xCCCCCC, "Zoom = - or + or scrolling");
	mlx_string_put(s->mlx, s->win, 10, 115, 0xCCCCCC, "Autozoom = z");
	mlx_string_put(s->mlx, s->win, 10, 135, 0xCCCCCC, "Reset = r");
	mlx_string_put(s->mlx, s->win, 10, 155, 0xCCCCCC, "Mandelbrot = m");
	mlx_string_put(s->mlx, s->win, 10, 175, 0xCCCCCC, "Julia = j");
	mlx_string_put(s->mlx, s->win, 10, 195, 0xCCCCCC, "Axone = a");
}
