/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 05:54:21 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/03 11:59:03 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_julia(char *str)
{
	if(!str)
		return ;
}

int	ft_mandelbrot(t_fractol *fract, t_complex *c)
{
	double		re_temp;
    t_complex	z;
    int			i;

    i = -1;
    z.r = 0;
    z.i = 0;
    while (sq(z) < 4 && ++i < fract->iteration)
    {
        re_temp = z.r * z.r - z.i * z.i + c->r;
        z.i = 2 * z.r * z.i + c->i;
        z.r = re_temp;
    }
    return (i);
}

