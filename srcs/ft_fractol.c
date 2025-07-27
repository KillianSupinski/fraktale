/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 05:54:21 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/27 17:52:10 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	ft_julia(t_fractol *f, t_complex z)
{
	double		re_temp;
	int			i;

	i = -1;
	while (sq(z) < 4 && ++i < f->iteration)
	{
		re_temp = z.r * z.r - z.i * z.i + f->cst.r;
		z.i = 2 * z.r * z.i + f->cst.i;
		z.r = re_temp;
	}
	return (i);
}

int	ft_mandelbrot(t_fractol *fract, t_complex *c)
{
	t_complex	z;
	double		re_temp;
	int			i;

	i = -1;
	z = c_new(0, 0);
	while (sq(z) < 4 && ++i < fract->iteration)
	{
		re_temp = z.r * z.r - z.i * z.i + c->r;
		z.i = 2 * z.r * z.i + c->i;
		z.r = re_temp;
	}
	return (i);
}
