/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 08:45:56 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/06/30 08:44:59 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_error(char *msg, t_data *d)
{
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display(d->mlx);
		free(d->mlx);
	}
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	ft_argerror()
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

int	main(int argc, char **argv)
{
	t_data data;

	data.win = NULL;
	if(argc > 2 || argc == 1)
		ft_argerror();
	if (argc == 2)
		ft_check_arg(argv);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		ft_error("mlx_init failed", &data);
	data.win = mlx_new_window(data.mlx, SIZE, SIZE, "fract-ol");
	if (data.win == NULL)
		ft_error("mlx_new_window failed", &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
