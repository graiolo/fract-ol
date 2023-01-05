/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:17:45 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/05 13:22:53 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	user_interface_texts(t_fractol *ptr)
{
	user_interface_texts_key(ptr);
	user_interface_texts_mouse(ptr);
	user_interface_texts_zoom(ptr);
}

void	user_interface_texts_key(t_fractol *ptr)
{
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, 35,
		0xC0C0C0, "Tasti di controllo");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, 63,
		0xC0C0C0, "Spostamento = ^ v < >");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, 83,
		0xC0C0C0, "Zoom nel centro = - e +");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, 103,
		0xC0C0C0, "Reset = R");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, 123,
		0xC0C0C0, "Colore successivo = C");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, 143,
		0xC0C0C0, "Colore precendente = X");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, 163,
		0xC0C0C0, "Nascondi legenda = CTRL");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, 183,
		0xC0C0C0, "ON/OFF iterazioni = S");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, 203,
		0xC0C0C0, "125 iterazioni = * e /");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, 223,
		0xC0C0C0, "Esci = ESC");


}

void	user_interface_texts_mouse(t_fractol *ptr)
{
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, (ptr->window_width - 155), 35,
		0xC0C0C0, "Controls Mouse");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, (ptr->window_width - 155), 63,
		0xC0C0C0, "Zoom = SCROLL");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, (ptr->window_height - 125),
		0xC0C0C0, "Fractal Explorer");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, (ptr->window_height - 95),
		0xC0C0C0, "1 = Julia");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, (ptr->window_height - 75),
		0xC0C0C0, "2 = Mandelbrot");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 37, (ptr->window_height - 55),
		0xC0C0C0, "3 = Tricorn");
}

void	user_interface_texts_zoom(t_fractol *ptr)
{
	char	*iteration;
	char	*n_zoom;

	n_zoom = ft_itoa(ptr->n_zoom);
	iteration = ft_itoa(ptr->max_iteration);
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, (ptr->window_width - 155),
		(ptr->window_height - 155), 0xC0C0C0, "Iterazioni Infos");
	if (ptr->zoom == true)
		mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, (ptr->window_width - 155),
			(ptr->window_height - 125), 0xC0C0C0, "Incremento: ON");
	else
		mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, (ptr->window_width - 155),
			(ptr->window_height - 125), 0xC0C0C0, "Incremento: OFF");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, (ptr->window_width - 155),
		(ptr->window_height - 105), 0xC0C0C0, "N iterazioni:");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, (ptr->window_width - 75),
		(ptr->window_height - 105), 0xC0C0C0, iteration);
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, (ptr->window_width - 155),
		(ptr->window_height - 85), 0xC0C0C0, "N zoom:");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, (ptr->window_width - 95),
		(ptr->window_height - 85), 0xC0C0C0, n_zoom);
	free(n_zoom);
	free(iteration);
}
