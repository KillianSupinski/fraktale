/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:27:04 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/10 11:38:59 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_clean_exit(t_data *d)
{
	if (d->img.ptr)
		mlx_destroy_image(d->mlx, d->img.ptr);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display(d->mlx);
		free(d->mlx);
	}
	exit(1);
}

void	ft_error(char *msg, t_data *d)
{
	ft_putstr_fd(msg, 2);
	ft_clean_exit(d);
}

void	ft_argerror(void)
{
	ft_printf("Les parametres disponible sont:\n");
	ft_printf("- mandelbrot\n- julia\n");
	exit(1);
}

void	ft_check_arg(char **argv)
{
	if (ft_strcmp(argv[1], "julia") == 0)
		return ;
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		return ;
	ft_argerror();
}
