/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:42:52 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/27 17:46:39 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	init_fract(t_fractol *f, char **argv, int ac)
{
	if (ft_strcmp(argv[1], "julia") == 0 && ac == 4)
	{
		f->cst.r = ft_atod(argv[2]);
		f->cst.i = ft_atod(argv[3]);
	}
	else
	{
		f->cst.r = -0.8;
		f->cst.i = 0.156;
	}
	f->xmin = -2.0;
	f->xmax = 1;
	f->ymin = -1.5;
	f->ymax = 1.5;
	f->type = argv[1];
	f->iteration = 80;
}

void	init_mlx(t_data *d, char **argv, int argc)
{
	d->mlx = mlx_init();
	if (!d->mlx)
		ft_error("mlx_init failed", d);
	d->win = mlx_new_window(d->mlx, SIZE, SIZE, "fract-ol");
	if (!d->win)
		ft_error("mlx_new_window failed", d);
	d->img.ptr = mlx_new_image(d->mlx, SIZE, SIZE);
	if (!d->img.ptr)
		ft_error("img failed", d);
	d->img.addr = mlx_get_data_addr(d->img.ptr, &d->img.bpp, \
								&d->img.l_len, &d->img.end);
	if (!d->img.addr)
		ft_error("addr failed", d);
	init_fract(&d->fract, argv, argc);
}
