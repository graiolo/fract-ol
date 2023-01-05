/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:58:55 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/03 16:10:09 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_draw_pixels(int x, int y, int color, t_fractol *ptr)
{
	int	i;
	int	*ptr2;

	i = y * ptr->img->line_length + x * ptr->img->bits_per_pixel / 8;
	ptr2 = (int *)&ptr->img->data[i];
	*ptr2 = color;
}

int	ft_put_image_to_window(t_fractol *ptr)
{
	if (ptr->img->mlx_img)
		mlx_destroy_image(ptr->mlx_ptr, ptr->img->mlx_img);
	ptr->img->mlx_img = mlx_new_image(ptr->mlx_ptr,
			ptr->window_width, ptr->window_height);
	ptr->img->data = mlx_get_data_addr(ptr->img->mlx_img,
			&ptr->img->bits_per_pixel, &ptr->img->line_length,
			&ptr->img->endian);
	if (ptr->fractal_name == 1)
		ft_launch_mandelbrot(ptr);
	if (ptr->fractal_name == 2)
		ft_launch_julia_set(ptr);
	if (ptr->fractal_name == 3)
		ft_launch_tricon(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
		ptr->img->mlx_img, 0, 0);
	if (ptr->help == true)
		user_interface_texts(ptr);
	else
		mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, (ptr->window_width - 225),
			(ptr->window_height - 10), 0xC0C0C0,
			"Premi CTRL per i tasti di controllo");
	return (0);
}
