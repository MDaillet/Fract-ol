/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:04:47 by mdaillet          #+#    #+#             */
/*   Updated: 2021/07/06 10:39:38 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_mouse_hook(int button, int x, int y, t_fract *s)
{
	if (button == 4)
	{
		s->x += x / 5;
		s->y += y / 5;
		s->z = s->z * 1.2;
		s->y = s->y * 1.2;
		s->x = s->x * 1.2;
		s->imax += 1;
	}
	if (button == 5)
	{
		if (s->z > 100)
		{
			s->x -= x / 5;
			s->y -= y / 5;
			s->z = s->z / 1.2;
			s->y = s->y / 1.2;
			s->x = s->x / 1.2;
			s->imax -= 1;
		}
	}
	ft_loop_hook(s);
	return (1);
}
