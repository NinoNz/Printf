/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printPtr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnzohab <alnzohab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:33 by alnzohab          #+#    #+#             */
/*   Updated: 2023/05/17 15:24:17 by alnzohab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexa_d2(unsigned long long n, int *len)
{
	unsigned long long	nbr;

	nbr = n;
	if (nbr >= 16)
	{
		ft_hexa_d2(nbr / 16, len);
		ft_hexa_d2(nbr % 16, len);
	}
	else if (nbr < 10)
	{
		ft_putchar_len(nbr + '0', len);
	}
	else
	{
		ft_putchar_len(nbr + 87, len);
	}
}

void	ft_print_ptr(unsigned long long n, int *len)
{
	ft_putstr_len("0x", len);
	ft_hexa_d2(n, len);
}
