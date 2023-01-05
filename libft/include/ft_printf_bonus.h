/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:35:31 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/21 16:35:34 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_flag
{
	bool	altform;
	bool	ladjust;
	bool	b_prec;
	bool	b_zeros;
	bool	f_check;
	char	plus_sign;
	char	pad;
	int		lenght;
	int		prec;
	int		zeros;
	int		num_sign;
	int		print_length;
}	t_flag;

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format, t_flag *flag);
int		ft_printchar(int c, t_flag *flag);
int		ft_printstr(char *str, t_flag *flag);
int		ft_print_ptr(unsigned long long ptr, t_flag *flag);
int		ft_printnbr(int n, t_flag *flag);
int		ft_print_unsigned(unsigned int n, t_flag *flag);
int		ft_print_hex(unsigned int num, const char format, t_flag *flag);
int		ft_printpercent(void);
int		ft_number_of_pad(char *str, t_flag flag);

int		ft_printf_pad(char *str, t_flag flag);
int		ft_putstr_error(char *str, t_flag flag);
void	ft_put_ptr(uintptr_t num);
int		ft_ptr_len(uintptr_t num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_hex_len(unsigned	int num);

int		ft_nzero_pzero(t_flag flag);
int		ft_only_nzero_hex(t_flag flag, unsigned int num);
int		ft_only_nzero_unsigned(t_flag flag, unsigned int n);
void	ft_b_prec_unsigned(t_flag flag, char *num,
			int *print_length, int pad_print);
void	ft_b_prec_hex(t_flag flag, unsigned int num,
			int *print_length, int pad_print);

void	*ft_realloc_negative(char *num);
void	ft_minus_num(char **num, int *print_length);

void	ft_b_prec_num(t_flag flag, char *num,
			int *print_length, int pad_printf);
void	ft_zeropad(t_flag *flag, int n, int *print_length, char *num);

int		ft_flags_set(const char *str, t_flag *flag);
int		ft_printf_pad_unsign(unsigned int n, t_flag flag, char *num);
int		ft_printf_pad_hex(unsigned int num, t_flag flag);
int		ft_test(unsigned int n, t_flag flag);

#endif
