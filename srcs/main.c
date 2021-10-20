/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                        `                       +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:26:08 by mdaillet          #+#    #+#             */
/*   Updated: 2021/07/07 16:55:08 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_arguments(int ac, char **av, t_fract *s)
{
	if (ac != 2)
	{
		ft_printf("Usage : ./fractol Mandelbrot/Julia/Axone");
		return (0);
	}
	if (ft_strcmp(av[1], "Mandelbrot") == 0
		|| ft_strcmp(av[1], "mandelbrot") == 0)
		s->fractal = mandelbrot;
	else if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "julia") == 0)
		s->fractal = julia;
	else if (ft_strcmp(av[1], "Axone") == 0 || ft_strcmp(av[1], "Axone") == 0)
		s->fractal = axone;
	if (s->fractal)
		return (1);
	ft_printf("Sorry, incorrect input. The available fractals are Mandelbrot,");
	ft_printf("Julia and Axone");
	return (0);
}

void	ft_autozoom(t_fract *s)
{
	s->z = s->z * 1.025;
	s->y = s->y * 1.025;
	s->x = s->x * 1.025;
	s->x += s->width / 80;
	s->y += s->height / 80;
	s->imax += 1;
}

int	ft_loop_hook(t_fract *s)
{
	if (s->autozoom)
		ft_autozoom(s);
	s->fractal(s);
	ft_put_string(s);
	return (1);
}

void	ft_free(t_fract *s)
{
	mlx_destroy_window(s->mlx, s->win);
	mlx_destroy_image(s->mlx, s->img);
	free(s->mand);
	s->mand = NULL;
	free(s->jul);
	s->jul = NULL;
	free(s->axo);
	s->axo = NULL;
	free(s);
	exit(0);
}

int	main(int ac, char **av)
{
	t_fract	*s;

	s = (t_fract *)ft_memalloc(sizeof(t_fract));
	if (!s || !ft_arguments(ac, av, s))
	{
		free(s);
		return (0);
	}
	if (!(ft_init(s)))
	{
		free(s);
		exit(0);
		return (0);
	}
	mlx_loop_hook(s->mlx, ft_loop_hook, s);
	mlx_key_hook(s->win, ft_key_hook, s);
	mlx_mouse_hook(s->win, ft_mouse_hook, s);
	mlx_loop(s->mlx);
	return (0);
}
