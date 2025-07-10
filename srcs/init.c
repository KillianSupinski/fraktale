/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:42:52 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/10 11:37:58 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	init_fract(t_fractol *f, char **argv)
{
	f->xmin = -2.0;
	f->xmax = 1;
	f->ymin = -1.5;
	f->ymax = 1.5;
	f->type = argv[1];
	f->iteration = 42;
}

void	init_mlx(t_data *d, char **argv)
{
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		ft_error("mlx_init failed", d);
	d->win = mlx_new_window(d->mlx, SIZE, SIZE, "fract-ol");
	if (d->win == NULL)
		ft_error("mlx_new_window failed", d);
	d->img.ptr = mlx_new_image(d->mlx, SIZE, SIZE);
	if (!d->img.ptr)
		ft_error("img failed", d);
	d->img.addr = mlx_get_data_addr(d->img.ptr, &d->img.bpp, \
								&d->img.l_len, &d->img.end);
	if (!d->img.addr)
		ft_error("addr failed", d);
	init_fract(&d->fract, argv);
}
