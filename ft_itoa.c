/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 12:15:43 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/01 15:41:48 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_size(long long int nb)
{
	unsigned int	nb_size;

	nb_size = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		nb_size = 1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		nb_size++;
	}
	return (nb_size);
}

static char		*fill_str(char *str, int len, long long int nbr)
{
	int				start;

	str[len + 1] = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
		start = 1;
	}
	else
		start = 0;
	while (len >= start)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char			*res;
	long long int	nbr;
	unsigned int	nb_size;

	nbr = n;
	nb_size = (unsigned int)ft_nb_size(n);
	if (nbr <= 0)
	{
		if (!(res = malloc(sizeof(char) * nb_size + 2)))
			return (NULL);
	}
	else
	{
		if (!(res = malloc(sizeof(char) * nb_size + 1)))
			return (NULL);
	}
	res = fill_str(res, nb_size, nbr);
	return (res);
}
