/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:17:21 by mdaillet          #+#    #+#             */
/*   Updated: 2021/07/06 17:59:01 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdint.h>
# include "struct.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define WIDTH 900
# define HEIGHT 600

int				main(int ac, char **av);
void			ft_free(t_fract *s);
t_fract			*ft_init(t_fract *s);
int				ft_init_fract(t_fract *s);
int				ft_arguments(int ac, char **av, t_fract *s);
void			mandelbrot(t_fract *s);
void			julia(t_fract *s);
void			axone(t_fract *s);
void			ft_autozoom(t_fract *s);
int				ft_hook_loop(t_fract *s);
int				ft_loop_hook(t_fract *s);
int				ft_key_hook(int keycode, t_fract *s);
int				ft_mouse_hook(int button, int x, int y, t_fract *s);
void			ft_put_string(t_fract *s);
unsigned int	ft_color(int i, t_fract *s);
void			ft_put_pxl(t_fract *s, int x, int y, int color);

#endif
