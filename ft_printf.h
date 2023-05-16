/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnzohab <alnzohab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:03:51 by alnzohab          #+#    #+#             */
/*   Updated: 2023/05/16 15:46:15 by alnzohab         ###   ########.fr       */
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

void	ft_hexaD(unsigned int n, int *len);
void	ft_hexaMaj(unsigned int n, int *len);
void	ft_putchar_len(char c, int *len);
void	ft_putnbr_len(int n, int fd, int *len);
void	ft_putnbr_U_(unsigned int n, int *len);
void	ft_putstr_len(char *s, int *len);

#endif