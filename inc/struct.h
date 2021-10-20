/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:15:28 by mdaillet          #+#    #+#             */
/*   Updated: 2021/07/06 10:54:35 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_fract
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*pxl;
	int					bpp;
	int					s_line;
	int					ed;
	int					width;
	int					height;
	void				(*fractal)();
	int					z;
	int					x;
	int					y;
	int					imax;
	int					psy;
	struct s_fractol	*mand;
	struct s_fractol	*jul;
	struct s_fractol	*axo;
	int					autozoom;
	unsigned int		color_value;
	unsigned int		color_max;
	int					r;
	int					g;
	int					b;
}				t_fract;

typedef struct s_fractol
{
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		zr;
	float		zi;
	float		cr;
	float		ci;
	float		tmp;
}				t_fractol;

#endif
