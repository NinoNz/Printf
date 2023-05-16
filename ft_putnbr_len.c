/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnzohab <alnzohab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:36:05 by alnzohab          #+#    #+#             */
/*   Updated: 2023/05/16 15:47:05 by alnzohab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_len(int n, int fd, int *len)
{
	int	nbr;

	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = n * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_len(nbr / 10, fd, len);
	}
	ft_putchar_len(nbr % 10 + '0', len);
}
