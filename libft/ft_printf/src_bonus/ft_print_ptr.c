/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:34:23 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/21 16:34:26 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

static int	ft_number_of_pad_ptr(int len_print, t_flag flag)
{
	int		l_pad;
	int		n_pad;

	len_print = ft_min(flag.prec, len_print);
	l_pad = flag.lenght - len_print;
	n_pad = ft_max(0, l_pad);
	return (n_pad);
}

static int	ft_printf_pad_ptr(int len_print, t_flag flag)
{
	int	n_pad;
	int	i;

	i = 0;
	n_pad = 0;
	n_pad = ft_number_of_pad_ptr(len_print, flag);
	while (n_pad != 0)
	{
		i += write(1, &flag.pad, 1);
		n_pad--;
	}
	return (i);
}

int	ft_ptr_len(uintptr_t num)
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

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr, t_flag *flag)
{
	if (ptr == 0)
	{
		flag->print_length += ft_putstr_error("(nil)", *flag);
		return (flag->print_length);
	}
	if (flag->ladjust == false)
		flag->print_length += ft_printf_pad_ptr(ft_ptr_len(ptr) + 2, *flag);
	flag->print_length += write(1, "0x", 2);
	ft_put_ptr(ptr);
	if (flag->ladjust == true)
		flag->print_length += ft_printf_pad_ptr(ft_ptr_len(ptr) + 2, *flag);
	flag->print_length += ft_ptr_len(ptr);
	return (flag->print_length);
}
