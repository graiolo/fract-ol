/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:47:34 by graiolo           #+#    #+#             */
/*   Updated: 2022/12/30 16:47:36 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	ft_init_hooks_and_loop(t_fractol *ptr)
{
	ft_init_mlx(ptr);
	mlx_hook(ptr->mlx_win, 2, 1, ft_key_hook, ptr);
	mlx_hook(ptr->mlx_win, 17, 0, (int (*)())ft_destroy_fractol, ptr);
	mlx_mouse_hook(ptr->mlx_win, ft_zoom_hook, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}

int	ft_init_mlx(t_fractol *ptr)
{
	ptr->mlx_ptr = mlx_init();
	if (ptr->fractal_name == 1)
		ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, ptr->window_width,
				ptr->window_height, "Mandelbrot");
	if (ptr->fractal_name == 2)
		ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, ptr->window_width,
				ptr->window_height, "Julia");
	if (ptr->fractal_name == 3)
		ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, ptr->window_width,
				ptr->window_height, "Tricon");
	ft_put_image_to_window(ptr);
	return (0);
}

void	ft_init_each_fractal_settings(t_fractol *ptr)
{
	if (ptr->fractal_name == 1)
		ft_mandelbrot_settings(ptr);
	if (ptr->fractal_name == 2)
		ft_julia_set_settings(ptr);
	if (ptr->fractal_name == 3)
		ft_tricon_settings(ptr);
}
