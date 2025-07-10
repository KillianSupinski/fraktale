/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 08:45:56 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/10 14:31:54 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.win = NULL;
	if (argc == 1)
		ft_argerror();
	if (argc == 2)
		ft_check_arg(argv);
	init_mlx(&data, argv);
	draw_fract(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, 4, 1L<<2, mouse_hook, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
