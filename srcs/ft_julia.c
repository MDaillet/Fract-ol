/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:56 by mdaillet          #+#    #+#             */
/*   Updated: 2021/07/05 13:07:51 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_iter_julia(t_fract *s)
{
	int		i;

	i = 0;
	while (i < s->imax)
	{
		s->jul->tmp = s->jul->zr;
		s->jul->zr = s->jul->zr * s->jul->zr - s->jul->zi * s->jul->zi
			+ s->jul->cr;
		s->jul->zi = 2 * s->jul->zi * s->jul->tmp + s->jul->ci;
		if (s->jul->zr * s->jul->zr + s->jul->zi * s->jul->zi >= 4)
			return (i);
		i++;
	}
	return (i);
}

void	julia(t_fract *s)
{
	int		x;
	int		y;

	x = s->x;
	while (x < s->width + s->x)
	{
		y = s->y;
		while (y < s->height + s->y)
		{
			s->jul->zr = (float)x / s->z + s->jul->x1;
			s->jul->zi = (float)y / s->z + s->jul->y1;
			s->jul->cr = 0.3;
			s->jul->ci = 0.5;
			ft_put_pxl(s, x - s->x, y - s->y, ft_color(ft_iter_julia(s), s));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
}
