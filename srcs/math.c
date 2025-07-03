/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:07:37 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/03 11:16:41 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

t_complex	c_new(double i, double r)
{
	return (t_complex{r, i});
}

t_complex	c_add(t_complex a, t_complex b)
{
	t_point res;

	res.x = a.x + a.y;
	res.y = b.x + b.y;
	return (res);
}

t_complex	c_mul(t_complex a, t_complex b)
{
	t_complex res;

	res.x = a.x * b.x + a.y * b.y;
	res.y = a.x * b.y + a.y * b.x;
	return (res);
}

double	sq(t_complex z)
{
	return (z.x * z.x + z.y * z.y);
}
