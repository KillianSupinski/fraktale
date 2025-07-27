/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:27:04 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/27 17:43:35 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_clean_exit(t_data *d, int ex)
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
	exit(ex);
}

void	ft_error(char *msg, t_data *d)
{
	ft_putstr_fd(msg, 2);
	ft_clean_exit(d, 1);
}

void	ft_argerror(void)
{
	ft_printf("Les parametres disponible sont:\n");
	ft_printf("- mandelbrot\n- julia (option 2 args: entre 1.99.. et -1.99..)\n");
	exit(1);
}

int	ft_check_julia(char *str)
{
	double	i;

	i = ft_atod(str);
	if (i > 2 || i < -2)
		return (1);
	return (0);
}

void	ft_check_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	if ((ft_strcmp(argv[1], "julia") == 0 && argc == 2) || \
						(ft_strcmp(argv[1], "julia") == 0 && argc == 4))
	{
		if (argc > 3)
		{
			i += ft_check_julia(argv[2]);
			i += ft_check_julia(argv[3]);
			if (i == 0)
				return ;
		}
		else if (argc == 2)
			return ;
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		return ;
	ft_argerror();
}
