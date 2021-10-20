/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_axone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:56:04 by mdaillet          #+#    #+#             */
/*   Updated: 2021/07/05 13:50:24 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_iter_axone(t_fract *s)
{
	int		i;

	i = 0;
	while (i < s->imax)
	{
		s->axo->tmp = s->axo->zr;
		s->axo->zr = s->axo->zr * s->axo->zr - s->axo->zi
			* s->axo->zi + s->axo->cr;
		s->axo->zi = 2 * s->axo->zi * s->axo->tmp + s->axo->ci;
		if (s->axo->zr * s->axo->zr + s->axo->zi * s->axo->zi >= 4)
			return (i);
		i++;
	}
	return (i);
}

void	axone(t_fract *s)
{
	int		x;
	int		y;

	x = s->x;
	while (x < s->width + s->x)
	{
		y = s->y;
		while (y < s->height + s->y)
		{
			s->axo->zr = (float)x / s->z + s->axo->x1;
			s->axo->zi = (float)y / s->z + s->axo->y1;
			s->axo->cr = 0;
			s->axo->ci = 1;
			ft_put_pxl(s, x - s->x, y - s->y, ft_color(ft_iter_axone(s), s));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
}
