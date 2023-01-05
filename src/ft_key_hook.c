/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:52:49 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/05 15:56:08 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	ft_key_hook(int keycode, t_fractol *ptr)
{
	if (keycode == ESC)
		ft_destroy_fractol(ptr);
	if (keycode == KEY_C)
		ptr->color = ptr->color + 0xF0A0F0;
	if (keycode == KEY_X)
		ptr->color = ptr->color - 0xF0A0F0;
	if (keycode == ARROW_PLUS)
		ft_zoom_hook(ZOOM_IN, ptr->center_x, ptr->center_y, ptr);
	if (keycode == ARROW_MIN)
		ft_zoom_hook(ZOOM_OUT, ptr->center_x, ptr->center_y, ptr);
	if (keycode == KEY_ASTERISC && ptr->zoom == true)
		ptr->max_iteration += 125;
	if (keycode == KEK_SLASH && ptr->zoom == true)
		ptr->max_iteration -= 125;
	if (ptr->max_iteration < 1)
		ptr->max_iteration = 1;
	ft_arrow_hook(keycode, ptr);
	ft_hook_switch(keycode, ptr);
	ft_key_switch(keycode, ptr);
	ft_put_image_to_window(ptr);
	return (0);
}

void	ft_key_switch(int keycode, t_fractol *ptr)
{
	if (keycode == KEY_ONE)
	{
		ptr->fractal_name = 2;
		ptr->c_real = 0.285;
		ptr->c_im = 0.013;
		ptr->display_shift = 0.1;
		ft_init_each_fractal_settings(ptr);
	}
	if (keycode == KEY_TWO)
	{
		ptr->fractal_name = 1;
		ptr->display_shift = 0.1;
		ft_init_each_fractal_settings(ptr);
	}
	if (keycode == KEY_TREE)
	{
		ptr->fractal_name = 3;
		ptr->display_shift = 0.1;
		ft_init_each_fractal_settings(ptr);
	}
}

void	ft_hook_switch(int keycode, t_fractol *ptr)
{
	if (keycode == KEY_R)
	{
		ptr->display_shift = 0.1;
		ft_init_each_fractal_settings(ptr);
	}
	if (keycode == KEY_CTRL)
	{
		if (ptr->help == true)
			ptr->help = false;
		else if (ptr->help == false)
			ptr->help = true;
	}
	if (keycode == KEY_S)
	{
		if (ptr->zoom == true)
			ptr->zoom = false;
		else if (ptr->zoom == false)
			ptr->zoom = true;
	}
}

void	ft_arrow_hook(int keycode, t_fractol *ptr)
{
	if (keycode == ARROW_UP)
	{
		ptr->y_min = ptr->y_min + ptr->display_shift;
		ptr->y_max = ptr->y_max + ptr->display_shift;
	}
	if (keycode == ARROW_DOWN)
	{
		ptr->y_min = ptr->y_min - ptr->display_shift;
		ptr->y_max = ptr->y_max - ptr->display_shift;
	}
	if (keycode == ARROW_LEFT)
	{
		ptr->x_min = ptr->x_min - ptr->display_shift;
		ptr->x_max = ptr->x_max - ptr->display_shift;
	}
	if (keycode == ARROW_RIGHT)
	{
		ptr->x_min = ptr->x_min + ptr->display_shift;
		ptr->x_max = ptr->x_max + ptr->display_shift;
	}
}
