/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaMaj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnzohab <alnzohab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:39:20 by alnzohab          #+#    #+#             */
/*   Updated: 2023/05/17 15:24:55 by alnzohab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_maj(unsigned long n, int *len)
{
	unsigned long	nbr;

	nbr = n;
	if (nbr >= 16)
	{
		ft_hexa_maj(nbr / 16, len);
		ft_hexa_maj(nbr % 16, len);
	}
	else if (nbr < 10)
	{
		ft_putchar_len(nbr + '0', len);
	}
	else
	{
		ft_putchar_len(nbr + 55, len);
	}
}
