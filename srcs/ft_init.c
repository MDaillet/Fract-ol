/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:38:11 by mdaillet          #+#    #+#             */
/*   Updated: 2021/07/06 13:56:12 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_fractol	*ft_init_fract2(void)
{
	t_fractol	*f;

	f = (t_fractol *)ft_memalloc(sizeof(t_fractol));
	if (!f)
		return (NULL);
	f->x1 = -2.1;
	f->y1 = -1.2;
	f->zr = 0;
	f->zi = 0;
	f->cr = 0;
	f->ci = 0;
	f->tmp = 0;
	return (f);
}

int	ft_init_fract(t_fract *s)
{
	s->mand = ft_init_fract2();
	if (!(s->mand))
		return (0);
	s->jul = ft_init_fract2();
	if (!(s->jul))
		return (0);
	s->axo = ft_init_fract2();
	if (!(s->axo))
		return (0);
	return (1);
}

t_fract	*ft_init(t_fract *s)
{
	s->width = WIDTH;
	s->height = HEIGHT;
	s->x = 1;
	s->y = 1;
	s->z = 250;
	s->color_max = 0x000000;
	s->mlx = mlx_init();
	s->imax = 75;
	s->color_value = 1;
	s->psy = 1;
	s->r = 5;
	s->g = 10;
	s->b = 2;
	s->img = mlx_new_image(s->mlx, s->width, s->height);
	s->pxl = mlx_get_data_addr(s->img, &(s->bpp), &(s->s_line), &(s->ed));
	if (!(ft_init_fract(s)))
		return (NULL);
	s->win = mlx_new_window(s->mlx, s->width, s->height, "Fract-ol");
	return (s);
}
