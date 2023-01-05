/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:47:20 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/05 13:13:25 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "ft_key.h"
# include "ft_fractol_struct.h"

# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>

# define NUM_THREADS 16

int				ft_main(int argc, char **argv);

int				ft_check_fractal_name(t_fractol *ptr, char **argv, int argc);

void			ft_init_each_fractal_settings(t_fractol *ptr);

int				ft_init_mlx(t_fractol *ptr);
void			ft_draw_pixels(int x, int y, int color, t_fractol *ptr);
int				ft_put_image_to_window(t_fractol *ptr);

void			ft_destroy_fractol(t_fractol *ptr);

bool			ft_check_cicle(t_fractol *ptr);

void			ft_help_calculate_mandelbrot(t_fractol *ptr);
void			ft_help_calculate_julia(t_fractol *ptr);
void			ft_help_calculate_tricon(t_fractol *ptr);

void			ft_mandelbrot_settings(t_fractol *ptr);
void			ft_init_mandelbrot(t_fractol *ptr);
void			ft_launch_mandelbrot(t_fractol *ptr);
void			*ft_calculate_mandelbrot(void *thread_data);

void			ft_validating_julia_parameters(int argc, char *argv[],
					t_fractol *ptr);
void			ft_julia_set_settings(t_fractol *ptr);
void			ft_init_julia_set(t_fractol *ptr);
void			ft_launch_julia_set(t_fractol *ptr);
void			*ft_calculate_julia_set(void *thread_data);

void			ft_tricon_settings(t_fractol *ptr);
void			ft_init_tricon(t_fractol *ptr);
void			ft_launch_tricon(t_fractol *ptr);
void			*ft_calculate_tricon(void *thread_data);

int				ft_key_hook(int keycode, t_fractol *ptr);
void			ft_arrow_hook(int keycode, t_fractol *ptr);
void			ft_hook_switch(int keycode, t_fractol *ptr);
void			ft_key_switch(int keycode, t_fractol *ptr);
void			ft_init_asix(t_asix *asix, int x, int y, t_fractol *ptr);
void			ft_asix_resizing(t_fractol *ptr, t_asix *asix);
void			ft_zoom_out(t_fractol *ptr, t_asix *asix);
void			ft_zoom_in(t_fractol *ptr, t_asix *asix);

int				ft_zoom_hook(int keycode, int x, int y, t_fractol *ptr);

int				ft_init_hooks_and_loop(t_fractol *ptr);

void			ft_message_error(t_fractol *ptr);
void			ft_julia_usage_message(t_fractol *ptr);

void			user_interface_texts(t_fractol *ptr);
void			user_interface_texts_key(t_fractol *ptr);
void			user_interface_texts_mouse(t_fractol *ptr);
void			user_interface_texts_zoom(t_fractol *ptr);

#		endif
