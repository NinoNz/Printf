/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnzohab <alnzohab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:03:46 by alnzohab          #+#    #+#             */
/*   Updated: 2023/05/18 11:43:21 by alnzohab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format_handler(char input, va_list *args, int *len)
{
	int	fd;

	fd = 1;
	if (input == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (input == 's')
		ft_putstr_len(va_arg(*args, char *), len);
	else if (input == 'd')
		ft_putnbr_len(va_arg(*args, int), fd, len);
	else if (input == 'i')
		ft_putnbr_len(va_arg(*args, int), fd, len);
	else if (input == 'u')
		ft_putnbr_u(va_arg(*args, unsigned int), len);
	else if (input == 'x')
		ft_hexa_d(va_arg(*args, unsigned int), len);
	else if (input == 'X')
		ft_hexa_maj(va_arg(*args, unsigned int), len);
	else if (input == 'p')
		ft_print_ptr(va_arg(*args, unsigned long), len);
	else if (input == '%')
		ft_putchar_len('%', len);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			ft_format_handler(input[i], &args, &len);
		}
		else
		{
			write(1, &input[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	printf("***** [c] characters *******\n");
// 	printf("%c\n", 65);
// 	ft_printf("%c", 65);
// 	printf("\n");

// 	printf("****** [s]strings ********\n");
// 	printf("%s\n", "nino");
// 	ft_printf("%s\n", "nino");
// 	printf("\n");

// 	printf("****** [d] decimals ******\n");
// 	printf("%d\n", 999999);
// 	ft_printf("%d", 999999);
// 	printf("\n");

// 	printf("**** [i] integers *****\n");
// 	printf("longeur: %d\n", printf("%i\n", -999999));
// 	printf("longeur: %d\n", ft_printf("%i\n", -999999));
// 	printf("\n");

// 	printf("**** [u] putU *****\n");
// 	printf("%u\n", -10);
// 	ft_printf("%u", -10);
// 	printf("\n");

// 	printf("**** [x] hexaMin *****\n");
// 	printf("%x\n", 1223);
// 	ft_printf("%x", 1223);
// 	printf("\n");

// 	printf("**** [X] hexaMaj *****\n");
// 	printf("%X\n", 42);
// 	ft_printf("%X", 42);
// 	printf("\n");

// 	printf("**** [p] pointeur *****\n");
// 	int i = 9999;
// 	int z = 132132;
// 	int *foo = &i;
// 	printf("value %p\n", &z);
// 	printf("longeur: %d\n", printf("value %p\n", &z));
// 	printf("\n------\n");
// 	ft_printf("value %p\n", &z);
// 	printf("longeur: %d\n", ft_printf("value %p\n", &z));
// 	printf("\n");

// 	printf("**** [%%] pourcentage *****\n");
// 	printf("%%\n");
// 	ft_printf("%%\n");
// 	printf("\n");
// }