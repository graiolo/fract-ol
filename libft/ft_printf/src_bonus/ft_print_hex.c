/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:34:10 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/21 16:34:13 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

static int	ft_number_of_pad_hex(unsigned int num, t_flag flag)
{
	int		len_print;
	int		l_pad;
	int		n_pad;

	len_print = ft_hex_len(num);
	if (num == 0)
		len_print++;
	if (flag.plus_sign != 0)
		len_print++;
	if (flag.b_prec == false)
		flag.prec = len_print;
	len_print = ft_max(flag.prec, len_print);
	l_pad = flag.lenght - len_print;
	n_pad = ft_max(0, l_pad);
	return (n_pad);
}

int	ft_printf_pad_hex(unsigned int num, t_flag flag)
{
	int	n_pad;
	int	i;

	i = 0;
	n_pad = 0;
	n_pad = ft_number_of_pad_hex(num, flag);
	while (n_pad != 0)
	{
		i += write(1, &flag.pad, 1);
		n_pad--;
	}
	return (i);
}

int	ft_print_hex(unsigned int num, const char format, t_flag *flag)
{
	int	pad_print;

	if (num == 0 && flag->prec == 0)
		return (ft_nzero_pzero(*flag));
	if (num == 0)
		return (ft_only_nzero_hex(*flag, num));
	if (flag->ladjust == false)
		flag->print_length += ft_printf_pad_hex(num, *flag);
	pad_print = flag->print_length;
	if (flag->pad == '0')
	{
		while (flag->print_length + ft_hex_len(num) < flag->lenght)
			flag->print_length += write(1, &(flag->pad), 1);
	}
	if (flag->b_prec == true)
		ft_b_prec_hex(*flag, num, &(flag->print_length), pad_print);
	if (flag->altform == true)
		flag->print_length += ft_printf("0%c", format);
	ft_put_hex(num, format);
	flag->print_length += ft_hex_len(num);
	if (flag->ladjust == true)
		flag->print_length += ft_printf_pad_hex(num, *flag);
	return (flag->print_length);
}
