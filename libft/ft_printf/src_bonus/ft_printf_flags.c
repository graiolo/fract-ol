/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:12:00 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/24 15:19:57 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

static void	ft_init_flags(t_flag *flag)
{
	flag->altform = false;
	flag->ladjust = false;
	flag->b_prec = false;
	flag->b_zeros = false;
	flag->f_check = false;
	flag->print_length = 0;
	flag->plus_sign = 0;
	flag->num_sign = 0;
	flag->lenght = 0;
	flag->zeros = 0;
	flag->prec = -1;
	flag->pad = ' ';
}

static bool	ft_flag_set_two(const char *str, t_flag *flag, int *i)
{
	if (str[*i] == '0')
	{
		flag->pad = '0';
		flag->b_zeros = true;
		flag->f_check = true;
		flag->zeros = 0;
		(*i)++;
		if (ft_isdigit(str[*i]))
		{
			while (ft_isdigit(str[*i]))
				flag->lenght = 10 * flag->lenght + str[(*i)++] - '0';
		}
		(*i)--;
	}
	if (flag->f_check == false)
		return (false);
	return (true);
}

static bool	ft_flag_set_one(const char *str, t_flag *flag, int *i)
{
	if (str[*i] == '#')
	{
		flag->altform = true;
		flag->f_check = true;
	}
	else if (str[*i] == '+')
	{
		flag->plus_sign = '+';
		flag->f_check = true;
	}
	else if (str[*i] == ' ')
	{
		flag->f_check = true;
		if (flag->plus_sign == 0)
			flag->plus_sign = ' ';
	}
	else if (str[*i] == '-')
	{
		flag->ladjust = true;
		flag->f_check = true;
	}
	flag->f_check = ft_flag_set_two(str, flag, i);
	if (flag->f_check == false)
		return (false);
	return (true);
}

static bool	ft_flag_set_tree(const char *str, t_flag *flag, int *i)
{
	if (ft_isdigit(str[*i]))
	{
		flag->f_check = true;
		while (ft_isdigit(str[*i]))
			flag->lenght = 10 * flag->lenght + str[(*i)++] - '0';
		(*i)--;
	}
	else if (str[*i] == '.')
	{
		(*i)++;
		flag->b_prec = true;
		flag->f_check = true;
		flag->prec = 0;
		if (ft_isdigit(str[*i]))
		{
			while (ft_isdigit(str[*i]))
				flag->prec = 10 * flag->prec + str[(*i)++] - '0';
		}
		(*i)--;
	}
	if (flag->f_check == false)
		return (false);
	return (true);
}

int	ft_flags_set(const char *str, t_flag *flag)
{
	int	i;

	i = 0;
	ft_init_flags(flag);
	while (true)
	{
		flag->f_check = false;
		if (ft_flag_set_one(str, flag, &i) == true)
			true ;
		else if (ft_flag_set_tree(str, flag, &i) == true)
			true ;
		else
			break ;
		i++;
	}
	if (flag->prec == -1)
		flag->prec = INT_MAX;
	if (flag->b_prec == true && flag->b_zeros == true)
		flag->pad = ' ';
	return (i);
}
