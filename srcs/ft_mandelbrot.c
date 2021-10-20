/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:53:00 by mdaillet          #+#    #+#             */
/*   Updated: 2021/07/06 13:50:02 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_iter_mand(t_fract *s)
{
	int	i;

	i = 0;
	while (i < s->imax)
	{
		s->mand->tmp = s->mand->zr;
		s->mand->zr = s->mand->zr * s->mand->zr - s->mand->zi * s->mand->zi
			+ s->mand->cr;
		s->mand->zi = 2 * s->mand->zi * s->mand->tmp + s->mand->ci;
		if (s->mand->zr * s->mand->zr + s->mand->zi * s->mand->zi >= 4)
			return (i);
		i++;
	}
	return (i);
}

void	mandelbrot(t_fract *s)
{
	int	x;
	int	y;

	x = s->x;
	while (x < s->width + s->x)
	{
		y = s->y;
		while (y < s->height + s->y)
		{
			s->mand->zr = 0;
			s->mand->zi = 0;
			s->mand->cr = (float)x / s->z + s->mand->x1;
			s->mand->ci = (float)y / s->z + s->mand->y1;
			ft_put_pxl(s, x - s->x, y - s->y, ft_color(ft_iter_mand(s), s));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
}
