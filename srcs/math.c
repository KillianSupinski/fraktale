/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:07:37 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/04 10:24:30 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

t_complex	c_mul(t_complex a, t_complex b)
{
	t_complex res;

	res.r = a.r * b.r + a.i * b.i;
	res.r = a.r * b.i + a.i * b.r;
	return (res);
}

double	sq(t_complex z)
{
	return (z.r * z.r + z.i * z.i);
}
