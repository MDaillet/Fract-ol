/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:42:18 by mdaillet          #+#    #+#             */
/*   Updated: 2021/06/07 16:33:41 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_width(int width, int len, int zero)
{
	int	i;

	i = 0;
	while (width - len > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		i++;
	}
	return (i);
}
