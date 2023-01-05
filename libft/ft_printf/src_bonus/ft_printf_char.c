/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:23:20 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/31 09:24:42 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

static int	ft_number_of_pad_char(char *str, t_flag flag)
{
	int		len_print;
	int		l_pad;
	int		n_pad;

	len_print = 0;
	if (ft_strlen(str) > 1)
		len_print = 1;
	else
		len_print = ft_strlen(str);
	len_print = ft_min(flag.prec, len_print);
	l_pad = flag.lenght - len_print;
	if (*str == 0 || flag.prec == 0)
		l_pad--;
	n_pad = ft_max(0, l_pad);
	return (n_pad);
}

static int	ft_printf_pad_char(char *str, t_flag flag)
{
	int	n_pad;
	int	i;

	i = 0;
	n_pad = 0;
	n_pad = ft_number_of_pad_char(str, flag);
	while (n_pad != 0)
	{
		i += write(1, &flag.pad, 1);
		n_pad--;
	}
	return (i);
}

int	ft_printchar(int c, t_flag *flag)
{
	int		i;
	char	f[1];

	i = 0;
	f[0] = (unsigned char)c;
	if (flag->ladjust == false)
		i += ft_printf_pad_char(f, *flag);
	if (flag->prec > -1)
		i += write(1, &c, 1);
	if (flag->ladjust == true)
		i += ft_printf_pad_char(f, *flag);
	return (i);
}
