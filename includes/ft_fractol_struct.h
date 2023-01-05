/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:50:21 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/05 13:14:12 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_STRUCT_H
# define FT_FRACTOL_STRUCT_H

typedef struct s_img
{
	void	*mlx_img;
	char	*data;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}t_img;

typedef struct s_fractol
{
	void	*mlx_win;
	void	*mlx_ptr;
	int		window_width;
	int		window_height;
	int		color;
	int		fractal_name;
	int		x;
	int		center_x;
	double	x_min;
	double	x_max;
	int		y;
	int		center_y;
	double	y_min;
	double	y_max;
	double	zoom_x;
	double	zoom_y;
	int		img_x;
	int		img_y;
	double	z_real;
	double	z_im;
	double	c_real;
	double	c_im;
	double	iteration;
	double	temp;
	float	display_shift;
	int		max_iteration;
	bool	help;
	bool	zoom;
	int		n_zoom;
	t_img	*img;
}				t_fractol;

typedef struct s_thread_data
{
	t_fractol	ptr;
	int			x_start;
	int			x_end;
}		t_thread_data;

typedef struct s_asix
{
	double	xratio;
	double	yratio;
	double	dre;
	double	dim;
}	t_asix;

#endif
