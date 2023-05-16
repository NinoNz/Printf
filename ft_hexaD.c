/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaD.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnzohab <alnzohab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:38:20 by alnzohab          #+#    #+#             */
/*   Updated: 2023/05/16 17:57:35 by alnzohab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexaD(unsigned int n, int *len)
{
	int nbr;

	nbr = n;
	if (nbr >= 16)
	{
		ft_hexaD(nbr / 16, len);
		ft_hexaD(nbr % 16, len);
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