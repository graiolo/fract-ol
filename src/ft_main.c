/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:00:34 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/05 13:14:48 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

/* ************** * 
 * helper:		  *
 *	mabaffo		  *
 *	ggiannit	  *
 *	btani		  *
 *	chatGPT		  *
 * ************** */

int	main(int argc, char **argv)
{
	t_fractol	*ptr;

	ptr = NULL;
	ptr = (t_fractol *)malloc(sizeof(t_fractol));
	if (!ptr)
		return (0);
	ptr->img = (t_img *)malloc(sizeof(t_img));
	if (!ptr->img)
		return (0);
	ptr->window_width = 800;
	ptr->window_height = 800;
	ptr->display_shift = 0.1;
	ptr->img->mlx_img = NULL;
	if (argc < 2 || argc > 4 || ft_check_fractal_name(ptr, argv, argc) != 1)
		ft_message_error(ptr);
	else
		ft_init_hooks_and_loop(ptr);
	return (0);
}
