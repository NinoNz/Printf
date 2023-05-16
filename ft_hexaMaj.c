/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaMaj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnzohab <alnzohab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:39:20 by alnzohab          #+#    #+#             */
/*   Updated: 2023/05/16 15:46:45 by alnzohab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexaMaj(unsigned int n, int *len)
{
	int nbr;

	nbr = n;
	if (nbr >= 16)
	{
		ft_hexaMaj(nbr / 16, len);
		ft_hexaMaj(nbr % 16, len);
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