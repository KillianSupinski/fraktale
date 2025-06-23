/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 08:45:56 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/06/23 14:49:30 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	MLX_ERROR(t_data *data)
{
	ft_printf("Error");
}



int	main(int argc, char **argv)
{
	t_data *data;

	if(argc > 2)
		return (NULL);
	data->mlx = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win = mlx_new_window(mlx, 1080, 720, "OK MLX");
	if (data->win == NULL)
	{
		free(data->win);
		return (0);
	}
	mlx_pixel_put(mlx, win, 300, 100, 0xd9138a);
	mlx_pixel_put(mlx, win, 540, 360, 0x79F8F8);
	mlx_loop(mlx);
}
