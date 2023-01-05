/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:33:33 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/24 14:39:31 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

int	ft_formats(va_list args, const char format, t_flag *flag)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int), flag);
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *), flag);
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long), flag);
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int), flag);
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int), flag);
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format, flag);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;
	t_flag	flag;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += ft_flags_set(&str[i + 1], &flag);
			print_length += ft_formats(args, str[i + 1], &flag);
			i++;
		}
		else
			print_length += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (print_length);
}
