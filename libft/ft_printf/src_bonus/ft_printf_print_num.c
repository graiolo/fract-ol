/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_num.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:02:28 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/31 11:07:36 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ft_printf_bonus.h"

void	*ft_realloc_negative(char *num)
{
	size_t	len;
	char	*using_num;
	char	*c_num;

	len = ft_strlen(num);
	c_num = (char *)num;
	using_num = malloc(len);
	while (len != 0)
	{
		using_num[len - 1] = c_num[len];
		len--;
	}
	free(num);
	return (using_num);
}

static int	ft_printstr_num(char *str, t_flag flag)
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

static int	ft_number_of_pad_num(int n, t_flag flag, char *num)
{
	int		len_print;
	int		l_pad;
	int		n_pad;

	(void)n;
	len_print = ft_strlen(num);
	if (flag.plus_sign != 0 || (flag.ladjust == true && n < 0))
	{
		len_print++;
		flag.prec++;
	}
	if (flag.ladjust == false && n < 0 && flag.lenght > flag.prec)
		flag.prec++;
	if (flag.b_prec == false)
		flag.prec = len_print;
	len_print = ft_max(flag.prec, len_print);
	l_pad = flag.lenght - len_print;
	n_pad = ft_max(0, l_pad);
	return (n_pad);
}

static int	ft_printf_pad_num(int n, t_flag flag, char *num)
{
	int	n_pad;
	int	i;

	i = 0;
	n_pad = 0;
	n_pad = ft_number_of_pad_num(n, flag, num);
	while (n_pad != 0)
	{
		i += write(1, &flag.pad, 1);
		n_pad--;
	}
	return (i);
}

int	ft_printnbr(int n, t_flag *flag)
{
	int		pad_print;
	char	*num;

	if (n < 0 || flag->plus_sign != 0)
		flag->num_sign++;
	if (n == 0 && flag->prec == 0)
		return (ft_nzero_pzero(*flag));
	num = ft_itoa(n);
	if (flag->ladjust == false && flag->pad != '0')
		flag->print_length += ft_printf_pad_num(n, *flag, num);
	if (n >= 0 && flag->plus_sign != 0)
		flag->print_length += write(1, &(flag->plus_sign), 1);
	if (n < 0)
		ft_minus_num(&num, &(flag->print_length));
	pad_print = flag->print_length;
	if (flag->pad == '0')
		ft_zeropad(flag, n, &(flag->print_length), num);
	if (flag->b_prec == true)
		ft_b_prec_num(*flag, num, &(flag->print_length), pad_print);
	flag->print_length += ft_printstr_num(num, *flag);
	if (flag->ladjust == true)
		flag->print_length += ft_printf_pad_num(n, *flag, num);
	free(num);
	return (flag->print_length);
}
