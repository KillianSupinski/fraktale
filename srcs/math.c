/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:07:37 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/16 16:17:29 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

t_complex	c_new(double r, double i)
{
	t_complex	z;

	z.r = r;
	z.i = i;
	return (z);
}

double	sq(t_complex z)
{
	return (z.r * z.r + z.i * z.i);
}
