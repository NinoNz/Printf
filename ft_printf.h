/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnzohab <alnzohab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:03:51 by alnzohab          #+#    #+#             */
/*   Updated: 2023/05/17 15:31:38 by alnzohab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_hexa_d(unsigned long n, int *len);
void	ft_hexa_maj(unsigned long n, int *len);
void	ft_putchar_len(char c, int *len);
void	ft_putnbr_len(long int n, int fd, int *len);
void	ft_putnbr_u(unsigned int n, int *len);
void	ft_putstr_len(char *s, int *len);
void	ft_print_ptr(unsigned long long n, int *len);
int		ft_printf(const char *input, ...);

#endif