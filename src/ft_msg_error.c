/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:31:16 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/08 16:00:06 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_message_error(t_fractol *ptr)
{	
	ft_printf("\n\t-----------------------------------------------------");
	ft_printf("---------------------------");
	ft_printf("\n\t| Errore, impossbile inizializzare il frattale \t\t\t\t       |\n");
	ft_printf("\t| Per generare un frattale, è necessario scegliere uno dei ");
	ft_printf("seguenti argomenti: |\n\t|\t\t\t\t\t\t\t\t\t       |\n\t| ");
	ft_printf("1. mandelbrot\t\t\t\t\t\t\t\t       |\n\t| 2. julia +");
	ft_printf("numero complesso compreso tra -2");
	ft_printf(".000 e 2.000 (±x.xxx ±x.xxx)       |\n\t| ");
	ft_printf("3. tricon      \t\t\t\t\t\t\t       |\n\t|\t\t\t\t\t\t\t\t\t       |\n");
	ft_printf("\t| Il che significa che il vostro input dovrebbe ");
	ft_printf("assomigliare a questo:\t       |\n\t|\t\t\t\t\t\t\t\t\t       |\n\t| ");
	ft_printf("./fractol julia -0,823 0,156\t\t\t\t\t\t       |");
	ft_printf("\n\t| ./fractol mandelbrot\t\t\t\t\t\t\t       |\n");
	ft_printf("\t| ./fractol tricon\t\t\t\t\t\t\t       |\n");
	ft_printf("\t----------------------------------------------------------");
	ft_printf("----------------------\n\n");
	free(ptr->img);
	free(ptr);
	exit(0);
}

void	ft_julia_usage_message(t_fractol *ptr)
{
	ft_printf("\n\t-----------------------------------------------------------");
	ft_printf("----------------------");
	ft_printf("\n\t| Per generare un frattale di Julia, è necessario ");
	ft_printf("digitare un\t\t\t|\n\t| numero complesso compreso ");
	ft_printf("tra -2.000 e 2.000 dopo la chiamata\t\t\t|\n");
	ft_printf("\t| ./fractol julia (±x.xxx ±x.xxx)\t\t\t\t\t\t|\n\t");
	ft_printf("|\t\t\t\t\t\t\t\t\t\t|\n\t| I numeri complessi sono composti da una parte");
	ft_printf(" reale ed una immaginaria.       |\n\t|");
	ft_printf(" Avrai quindi bisogno di due vaolori ");
	ft_printf("differenti separati da uno spazio (' ')   |\n\t|\t\t\t\t\t\t\t\t\t\t|");
	ft_printf("\n\t| Come segue:\t\t\t\t\t\t\t\t \t|\n\t|\t\t\t\t\t\t\t\t\t\t|\n\t| ");
	ft_printf("\t0.701 -0.382\t\t\t\t\t\t\t\t|\n\t| \t0.000 -0.800\t\t\t\t\t\t\t\t|");
	ft_printf("\n\t|\t-0.835 -0.2321\t\t\t\t\t\t\t\t|");
	ft_printf("\n\t-----------------------------------------------------------");
	ft_printf("----------------------\n\n");
	free(ptr->img);
	free(ptr);
	exit(0);
}
