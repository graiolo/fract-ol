/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_julia_set.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:45:51 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/05 13:15:54 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_validating_julia_parameters(int argc, char *argv[], t_fractol *ptr)
{
	if (argc == 4)
	{
		ptr->c_real = ft_atof(argv[2]);
		ptr->c_im = ft_atof(argv[3]);
		ft_julia_set_settings(ptr);
		if (ptr->c_real < ptr->x_min || ptr->c_real > ptr->x_max)
			ft_julia_usage_message(ptr);
		if (ptr->c_im < ptr->y_min || ptr->c_im > ptr->y_max)
			ft_julia_usage_message(ptr);
	}
	else
		ft_julia_usage_message(ptr);
}

void	ft_julia_set_settings(t_fractol *ptr)
{
	ptr->img_x = ptr->window_width;
	ptr->img_y = ptr->window_height;
	ptr->center_x = ptr->window_width / 2;
	ptr->center_y = ptr->window_height / 2;
	ptr->iteration = 0;
	ptr->x_min = -2.0;
	ptr->x_max = 2.0;
	ptr->y_min = -2.0;
	ptr->y_max = 2.0;
	ptr->zoom_x = (ptr->x_max - ptr->x_min) / ptr->window_width;
	ptr->zoom_y = (ptr->y_max - ptr->y_min) / ptr->window_height;
	ptr->z_real = 0;
	ptr->z_im = 0;
	ptr->max_iteration = 2782;
	ptr->color = 0x212120;
	ptr->help = true;
	ptr->zoom = true;
	ptr->n_zoom = 0;
}

void	ft_init_julia_set(t_fractol *ptr)
{
	ptr->iteration = 0;
	ptr->z_real = 0;
	ptr->z_im = 0;
	ptr->z_real = ptr->x * ((ptr->x_max - ptr->x_min)
			/ ptr->window_width) + ptr->x_min;
	ptr->z_im = ptr->y_max - ptr->y * ((ptr->y_max - ptr->y_min)
			/ ptr->window_height);
}

void	ft_launch_julia_set(t_fractol *ptr)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_datas[NUM_THREADS];
	int				i;

	i = -1;
	while (++i < NUM_THREADS)
	{
		thread_datas[i].ptr = *ptr;
		thread_datas[i].x_start = (i * ptr->img_x / NUM_THREADS) - 1;
		thread_datas[i].x_end = (i + 1) * ptr->img_x / NUM_THREADS;
		pthread_create(&threads[i], NULL, ft_calculate_julia_set,
			(void*)(&thread_datas[i]));
	}
	i = 0;
	while (i < NUM_THREADS)
		pthread_join(threads[i++], NULL);
}

void	*ft_calculate_julia_set(void *thread_data)
{
	t_thread_data	*data;
	t_fractol		*ptr;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	data = (t_thread_data *)thread_data;
	ptr = &data->ptr;
	ptr->x = data->x_start;
	while (++(ptr->x) < data->x_end)
	{
		ptr->y = 0;
		while (ptr->y < ptr->img_y)
		{
			ft_init_julia_set(ptr);
			while (ft_check_cicle(ptr) == true)
				ft_help_calculate_julia(ptr);
			pthread_mutex_lock(&mutex);
			ft_draw_pixels(ptr->x, ptr->y, ptr->iteration
				/ ptr->max_iteration * ptr->color, ptr);
			pthread_mutex_unlock(&mutex);
			ptr->y++;
		}
	}
	pthread_mutex_destroy(&mutex);
	return (NULL);
}
