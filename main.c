/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 08:45:56 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/25 08:48:22 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	main()
{
	void *mlx  = mlx_init();
	void *win  = mlx_new_window(mlx, 400, 200, "OK MLX");

	mlx_pixel_put(mlx, win, 200, 100, 0x00FF00);   // pixel vert au centre
	mlx_loop(mlx);
}
