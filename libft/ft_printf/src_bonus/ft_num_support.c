/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:55:45 by graiolo           #+#    #+#             */
/*   Updated: 2022/11/03 12:59:13 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

void	ft_b_prec_num(t_flag flag, char *num,
			int *print_length, int pad_print)
{
	if (flag.ladjust == false)
		while (*print_length + (int)ft_strlen(num) - pad_print < flag.prec)
			*print_length += write(1, "0", 1);
	else
		while (*print_length + (int)ft_strlen(num) < flag.prec + flag.num_sign)
			*print_length += write(1, "0", 1);
}

void	ft_zeropad(t_flag *flag, int n, int *print_length, char *num)
{
	if (flag->pad == '0' && n < 0)
		flag->prec--;
	while (*print_length + (int)ft_strlen(num) < flag->lenght)
		*print_length += write(1, &flag->pad, 1);
}

void	ft_minus_num(char **num, int *print_length)
{
	*print_length += write(1, "-", 1);
	*num = ft_realloc_negative(*num);
}

int	ft_test(unsigned int n, t_flag flag)
{
	int	i;
	int	n_pad;

	i = 0;
	n_pad = flag.lenght - n;
	if (n_pad > 0)
	{
		while (n_pad != 0)
		{
			i += write(1, &flag.pad, 1);
			n_pad--;
		}
	}
	return (i);
}
