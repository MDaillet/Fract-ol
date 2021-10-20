/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pxl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:39:06 by mdaillet          #+#    #+#             */
/*   Updated: 2021/07/04 14:48:21 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_put_pxl(t_fract *s, int x, int y, int color)
{
	int	i;

	i = (x * 4) + (y * s->s_line);
	s->pxl[i] = color;
	s->pxl[++i] = color >> 8;
	s->pxl[++i] = color >> 16;
}

unsigned int	ft_color(int i, t_fract *s)
{
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (i == s->imax)
		return (s->color_max);
	r = s->psy * i * s->r;
	g = s->psy * i * s->g;
	b = s->psy * i * s->b;
	color = (r << 16) + (g << 8) + b;
	return (color);
}
