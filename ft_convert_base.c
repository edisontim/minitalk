/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:23:10 by tedison           #+#    #+#             */
/*   Updated: 2021/06/02 18:06:33 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

void	ft_my_putnbr_base(char *tab, int nb, char *base, int *index)
{
	unsigned int	nbr;
	unsigned int	size;

	size = 0;
	while (base[size])
		size++;
	nbr = nb;
	if (nbr < size)
	{
		tab[*index] = base[nbr];
		*index = *index + 1;
	}
	else
	{
		ft_my_putnbr_base(tab, nbr / size, base, index);
		ft_my_putnbr_base(tab, nbr % size, base, index);
	}
	return ;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_convert_base(char *nbr, unsigned int *size)
{
	char	*to_return;
	int		index;
	int		to_malloc;
	int		to_return_index;
	int		i;

	i = 0;
	index = 0;
	to_return_index = 0;
	to_malloc = 8 * ft_strlen(nbr);
	*size = to_malloc;
	to_return = malloc(sizeof(*to_return) * (to_malloc + 1));
	if (to_return == NULL)
		return (NULL);
	while (nbr[index])
	{
		i = 7;
		while (i >= 0)
			to_return[to_return_index++] = ((nbr[index] >> i--) & 0x01) + 48;
		index++;
	}
	to_return[to_return_index] = '2';
	return (to_return);
}
