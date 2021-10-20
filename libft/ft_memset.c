/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:57:14 by mdaillet          #+#    #+#             */
/*   Updated: 2020/10/14 16:57:50 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*buc;

	i = 0;
	buc = (unsigned char *)b;
	while (i < len)
	{
		buc[i] = c;
		i++;
	}
	return (b = buc);
}
