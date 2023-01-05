/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:01:01 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/05 13:24:16 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	ft_zoom_hook(int keycode, int x, int y, t_fractol *ptr)
{
	t_asix	*asix;

	asix = (t_asix *)malloc(sizeof(t_asix));
	if (asix == NULL)
		return (0);
	ft_init_asix(asix, x, y, ptr);
	if (keycode == CLICK_LEFT || keycode == CLICK_RIGHT
		|| keycode == CLICK_MIDDLE)
		return (0);
	if (keycode == ZOOM_OUT || keycode == ARROW_MIN)
		ft_zoom_out(ptr, asix);
	if (keycode == ZOOM_IN || keycode == ARROW_PLUS)
		ft_zoom_in(ptr, asix);
	ft_asix_resizing(ptr, asix);
	ft_put_image_to_window(ptr);
	return (0);
}

void	ft_zoom_out(t_fractol *ptr, t_asix *asix)
{
	ptr->n_zoom -= 1;
	ptr->zoom_x *= 1.1;
	ptr->zoom_y *= 1.1;
	ptr->display_shift *= 1.1;
	asix->dre = (1.1 * asix->dre) - asix->dre;
	asix->dim = (1.1 * asix->dim) - asix->dim;
	if (ptr->max_iteration > 32 && ptr->zoom == true)
		ptr->max_iteration -= 1;
}

void	ft_zoom_in(t_fractol *ptr, t_asix *asix)
{
	ptr->n_zoom += 1;
	ptr->zoom_x /= 1.1;
	ptr->zoom_y /= 1.1;
	ptr->display_shift /= 1.1;
	asix->dre = 0.909 * asix->dre - asix->dre;
	asix->dim = 0.909 * asix->dim - asix->dim;
	if (ptr->max_iteration < 1250 && ptr->zoom == true)
		ptr->max_iteration += 1;
}

void	ft_init_asix(t_asix *asix, int x, int y, t_fractol *ptr)
{
	asix->xratio = (double)x / (double)ptr->img_x;
	asix->yratio = (double)y / (double)ptr->img_y;
	asix->dre = ptr->x_max - ptr->x_min;
	asix->dim = ptr->y_max - ptr->y_min;
}

void	ft_asix_resizing(t_fractol *ptr, t_asix *asix)
{
	ptr->x_min = ptr->x_min - asix->dre * asix->xratio;
	ptr->x_max = ptr->x_max + asix->dre * (1 - asix->xratio);
	ptr->y_max = ptr->y_max + asix->dim * asix->yratio;
	ptr->y_min = ptr->y_min - asix->dim * (1 - asix->yratio);
}
