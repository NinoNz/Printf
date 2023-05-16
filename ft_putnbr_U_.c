/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_U_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnzohab <alnzohab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:37:35 by alnzohab          #+#    #+#             */
/*   Updated: 2023/05/16 15:47:32 by alnzohab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_U_(unsigned int n, int *len)
{
	int nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_putnbr_U_(nbr / 10, len);
	}
	ft_putchar_len(nbr % 10 + '0', len);
}