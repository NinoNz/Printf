/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnzohab <alnzohab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:03:46 by alnzohab          #+#    #+#             */
/*   Updated: 2023/05/16 19:02:44 by alnzohab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

static void	ft_hexaD2(unsigned long long n, int *len)
{
	unsigned long long nbr;

	nbr = n;
	if (nbr >= 16)
	{
		
		ft_hexaD2(nbr / 16, len);
		ft_hexaD2(nbr % 16, len);
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

static void ft_printPtr(unsigned long long n, int *len)
{
	ft_putstr_len("0x", len);
	
	
	ft_hexaD2(n, len);
	
}

static void	ft_format_handler(char input, va_list *args, int *len)
{
	int	fd;

	fd = 1;
	if (input == 'c')
	{
		ft_putchar_len(va_arg(*args, int), len);
	}
	else if (input == 's')
	{
		ft_putstr_len(va_arg(*args, char *), len);
	}
	else if (input == 'd')
	{
		ft_putnbr_len(va_arg(*args, int), fd, len);
	}
	else if (input == 'i')
	{
		ft_putnbr_len(va_arg(*args, int), fd, len);
	}
	else if (input == 'u')
	{
		ft_putnbr_U_(va_arg(*args, int), len);
	}
	else if (input == 'x')
	{
		ft_hexaD(va_arg(*args, int), len);
	}
	else if (input == 'X')
	{
		ft_hexaMaj(va_arg(*args, int), len);
	}
	else if (input == 'p')
	{
		ft_printPtr(va_arg(*args, unsigned long), len);
	}
	else if (input == '%')
	{
		ft_putchar_len('%', len);	
	}
}

int	ft_printf(const char *input, ...)
{
	int i;        //index du input passé en param = (*s)
	int len;      // longeur du input passé en param = (*s)
	va_list args; // liste d'arguments de formatage
	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			ft_format_handler(input[i], &args, &len);
			i++;
			// printf("\nloop\n");
			// sleep(1);
		}
		else
			write(1, &input[i], 1);
		// imprimer les chars peut importe.
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
// 	printf("%i\n", 999999);
// 	ft_printf("%i", 999999);
// 	printf("\n");

// 	printf("**** [u] putU *****\n");
// 	printf("%u\n", 429496729);
// 	ft_printf("%u", 429496729);
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
// 	int	z = 6666;
// 	int* foo = &i;
// 	printf("value %p\n", &z);
// 	printf("------\n");
// 	ft_printf("value %p\n", &z);
// 	printf("\n");


// 	printf("**** [%%] pourcentage *****\n");
// 	printf("%%\n");
// 	ft_printf("%%");
// 	printf("\n");
// }