/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_unsigned_support.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:49:17 by graiolo           #+#    #+#             */
/*   Updated: 2022/11/03 10:51:27 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

int	ft_nzero_pzero(t_flag flag)
{
	int	print_length;

	print_length = 0;
	while (flag.lenght--)
		print_length += write(1, &flag.pad, 1);
	return (print_length);
}

int	ft_only_nzero_hex(t_flag flag, unsigned int num)
{
	int	print_length;

	print_length = 0;
	if (flag.ladjust == false)
		print_length += ft_printf_pad_hex(num, flag);
	if (flag.pad == '0')
	{
		while (print_length + 1 < (int)flag.lenght)
			print_length += write(1, &flag.pad, 1);
	}
	if (flag.b_prec == true && flag.pad != '0')
	{
		if (num != 0)
			while (print_length + 1 < flag.prec)
				print_length += write(1, "0", 1);
		else
			while (--flag.prec)
				print_length += write(1, "0", 1);
	}
	print_length += write(1, "0", 1);
	if (flag.ladjust == true)
		print_length += ft_test(print_length, flag);
	return (print_length);
}

int	ft_only_nzero_unsigned(t_flag flag, unsigned int n)
{
	int	print_length;

	print_length = 0;
	if (flag.ladjust == false)
		print_length += ft_printf_pad_unsign(n, flag, "0");
	if (flag.pad == '0')
	{
		while (print_length + 1 < (int)flag.lenght)
			print_length += write(1, &flag.pad, 1);
	}
	if (flag.b_prec == true && flag.pad != '0')
	{
		if (n != 0)
			while (print_length + 1 < flag.prec)
				print_length += write(1, "0", 1);
		else
			while (--flag.prec)
				print_length += write(1, "0", 1);
	}
	print_length += write(1, "0", 1);
	if (flag.ladjust == true)
		print_length += ft_test(print_length, flag);
	return (print_length);
}

void	ft_b_prec_unsigned(t_flag flag, char *num,
			int *print_length, int pad_print)
{
	if (flag.ladjust == false)
		while (*print_length + (int)ft_strlen(num) - pad_print < flag.prec)
			*print_length += write(1, "0", 1);
	else
		while (*print_length + (int)ft_strlen(num) < flag.prec)
			*print_length += write(1, "0", 1);
}

void	ft_b_prec_hex(t_flag flag, unsigned int num,
			int *print_length, int pad_print)
{
	if (flag.ladjust == false)
		while (*print_length + (int)ft_hex_len(num) - pad_print < flag.prec)
			*print_length += write(1, "0", 1);
	else
		while (*print_length + (int)ft_hex_len(num) < flag.prec)
			*print_length += write(1, "0", 1);
}
