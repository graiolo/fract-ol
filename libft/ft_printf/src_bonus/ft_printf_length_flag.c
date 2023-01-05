/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length_flag.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:33:45 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/31 09:34:20 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

int	ft_number_of_pad(char *str, t_flag flag)
{
	int		len_print;
	int		l_pad;
	int		n_pad;

	len_print = 0;
	if (str == NULL)
		len_print = 0;
	if (str == NULL && flag.prec > 5)
		len_print = 6;
	else if (str != NULL)
		len_print = ft_strlen(str);
	len_print = ft_min(flag.prec, len_print);
	l_pad = flag.lenght - len_print;
	n_pad = ft_max(0, l_pad);
	return (n_pad);
}

int	ft_printf_pad(char *str, t_flag flag)
{
	int	n_pad;
	int	i;

	i = 0;
	n_pad = 0;
	n_pad = ft_number_of_pad(str, flag);
	while (n_pad != 0)
	{
		i += write(1, &flag.pad, 1);
		n_pad--;
	}
	return (i);
}
