/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:34:31 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/21 16:34:33 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

static int	ft_printstr_unsign(char *str, t_flag flag)
{
	int	i;
	int	len;

	(void) flag;
	len = 0;
	i = 0;
	if (str == NULL)
	{
		len += ft_putstr_error("(null)", flag);
		return (len);
	}
	while (str[i])
	{
		len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}

static int	ft_number_of_pad_unsign(unsigned int n, t_flag flag, char *num)
{
	int		len_print;
	int		l_pad;
	int		n_pad;

	(void) n;
	len_print = ft_strlen(num);
	if (flag.plus_sign != 0)
		len_print++;
	if (flag.b_prec == false)
		flag.prec = len_print;
	len_print = ft_max(flag.prec, len_print);
	l_pad = flag.lenght - len_print;
	n_pad = ft_max(0, l_pad);
	return (n_pad);
}

int	ft_printf_pad_unsign(unsigned int n, t_flag flag, char *num)
{
	int	n_pad;
	int	i;

	i = 0;
	n_pad = 0;
	n_pad = ft_number_of_pad_unsign(n, flag, num);
	while (n_pad != 0)
	{
		i += write(1, &flag.pad, 1);
		n_pad--;
	}
	return (i);
}

int	ft_print_unsigned(unsigned int n, t_flag *flag)
{
	int		pad_print;
	char	*num;

	if (n == 0 && flag->prec == 0)
		return (ft_nzero_pzero(*flag));
	if (n == 0)
		return (ft_only_nzero_unsigned(*flag, n));
	num = ft_uitoa(n);
	if (flag->ladjust == false)
		flag->print_length += ft_printf_pad_unsign(n, *flag, num);
	pad_print = flag->print_length;
	if (flag->pad == '0')
	{
		while (flag->print_length + (int)ft_strlen(num) < flag->lenght)
			flag->print_length += write(1, &(flag->pad), 1);
	}
	if (flag->b_prec == true)
		ft_b_prec_unsigned(*flag, num, &(flag->print_length), pad_print);
	flag->print_length += ft_printstr_unsign(num, *flag);
	if (flag->ladjust == true)
		flag->print_length += ft_printf_pad_unsign(n, *flag, num);
	free(num);
	return (flag->print_length);
}
