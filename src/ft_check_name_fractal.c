/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name_fractal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:56:50 by graiolo           #+#    #+#             */
/*   Updated: 2022/12/30 16:57:26 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	ft_check_fractal_name(t_fractol *ptr, char **argv, int argc)
{
	if (!ft_strncmp("mandelbrot\0", argv[1], 11))
		ptr->fractal_name = 1;
	else if (!ft_strncmp("julia\0", argv[1], 6))
	{
		ptr->fractal_name = 2;
		ft_validating_julia_parameters(argc, argv, ptr);
	}
	else if (!ft_strncmp("tricon\0", argv[1], 7))
		ptr->fractal_name = 3;
	else
		return (0);
	ft_init_each_fractal_settings(ptr);
	return (1);
}
