/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:29:37 by mdaillet          #+#    #+#             */
/*   Updated: 2021/07/07 16:56:33 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_key_hook5(int keycode, t_fract *s)
{
	if (keycode == 114)
	{
		s->imax = 75;
		s->color_value = 1;
		s->psy = 1;
		s->r = 5;
		s->g = 10;
		s->b = 2;
		s->x = 1;
		s->y = 1;
		s->z = 250;
		s->color_max = 0x000000;
	}
	if (keycode == 50)
	{
		if (s->psy < 255)
			s->psy += 1;
		else
			s->psy = 1;
	}
	return (1);
}

int	ft_key_hook4(int keycode, t_fract *s)
{
	if (keycode == 49)
	{
		if (s->psy > 1)
			s->psy -= 1;
		else
			s->psy = 255;
	}
	if (keycode == 51)
	{
		s->r = 10;
		s->g = 2;
		s->b = 5;
	}
	if (keycode == 52)
	{
		s->r = 2;
		s->g = 5;
		s->b = 10;
	}
	return (1);
}

int	ft_key_hook3(int keycode, t_fract *s)
{
	if (keycode == 65361)
		s->x -= 60;
	if (keycode == 65363)
		s->x += 60;
	if (keycode == 65362)
		s->y -= 60;
	if (keycode == 65364)
		s->y += 60;
	if (keycode == 65451)
	{
		s->z = s->z * 1.2;
		s->y = s->y * 1.2;
		s->x = s->x * 1.2;
	}
	if (keycode == 65453 || keycode == 45)
	{
		if (s->z > 100)
		{
			s->z = s->z / 1.2;
			s->y = s->y / 1.2;
			s->x = s->x / 1.2;
		}
	}
	return (1);
}

int	ft_key_hook2(int keycode, t_fract *s)
{
	if (keycode == 109)
		s->fractal = mandelbrot;
	if (keycode == 106)
		s->fractal = julia;
	if (keycode == 97)
		s->fractal = axone;
	return (1);
}

int	ft_key_hook(int keycode, t_fract *s)
{
	if (keycode == 65307)
		ft_free(s);
	if (keycode == 122)
	{
		if (!s->autozoom)
			s->autozoom = 1;
		else
			s->autozoom = 0;
	}
	ft_key_hook5(keycode, s);
	ft_key_hook4(keycode, s);
	ft_key_hook3(keycode, s);
	ft_key_hook2(keycode, s);
	ft_put_string(s);
	ft_loop_hook(s);
	return (1);
}
