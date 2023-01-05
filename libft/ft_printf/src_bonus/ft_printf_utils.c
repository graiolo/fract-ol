/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:33:54 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/21 16:33:58 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

int	ft_putstr_error(char *str, t_flag flag)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (flag.ladjust == false)
		len += ft_printf_pad(str, flag);
	while (str[i])
	{
		len += write(1, &str[i], 1);
		i++;
	}
	if (flag.ladjust == true)
		len += ft_printf_pad(str, flag);
	return (len);
}

int	ft_printstr(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	if (str == NULL)
	{	
		if (flag->prec < 6)
			flag->print_length += ft_printf_pad(NULL, *flag);
		if (flag->prec > 5)
			flag->print_length += ft_putstr_error("(null)", *flag);
		return (flag->print_length);
	}
	if (flag->ladjust == false)
		flag->print_length += ft_printf_pad(str, *flag);
	while (str[i] && i < flag->prec)
	{
		flag->print_length += write(1, &str[i], 1);
		i++;
	}
	if (flag->ladjust == true)
		flag->print_length += ft_printf_pad(str, *flag);
	return (flag->print_length);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
