/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:57:31 by graiolo           #+#    #+#             */
/*   Updated: 2022/12/30 16:12:24 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

bool	ft_check_cicle(t_fractol *ptr)
{
	if (ptr->z_real * ptr->z_real + ptr->z_im
		* ptr->z_im < 4 && ptr->iteration < ptr->max_iteration)
		return (true);
	return (false);
}

void	ft_help_calculate_mandelbrot(t_fractol *ptr)
{
	ptr->temp = ptr->z_real;
	ptr->z_real = ptr->z_real * ptr->z_real
		- ptr->z_im * ptr->z_im + ptr->c_real;
	ptr->z_im = 2 * ptr->z_im * ptr->temp + ptr->c_im;
	ptr->iteration++;
}

void	ft_help_calculate_julia(t_fractol *ptr)
{
	ptr->temp = ptr->z_real;
	ptr->z_real = ptr->z_real * ptr->z_real
		- ptr->z_im * ptr->z_im + ptr->c_real;
	ptr->z_im = 2 * ptr->z_im * ptr->temp + ptr->c_im;
	ptr->iteration++;
}

void	ft_help_calculate_tricon(t_fractol *ptr)
{
	ptr->temp = ptr->z_real * ptr->z_real
		- ptr->z_im * ptr->z_im + ptr->c_real;
	ptr->z_im = -2.0 * ptr->z_real * ptr->z_im + ptr->c_im;
	ptr->z_real = ptr->temp;
	ptr->iteration++;
}
