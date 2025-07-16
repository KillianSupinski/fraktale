/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:58:51 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/16 17:06:05 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	zoom_rect(t_fractol *f, t_complex centre, double factor)
{
	double	range_x;
	double	range_y;

	range_x = (f->xmax - f->xmin) * factor;
	range_y = range_x;
	f->xmin = centre.r - range_x * 0.5;
	f->xmax = centre.r + range_x * 0.5;
	f->ymin = centre.i - range_y * 0.5;
	f->ymax = centre.i + range_y * 0.5;
}
