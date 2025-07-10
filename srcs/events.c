/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 09:32:07 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/10 15:09:13 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_clean_exit(data);
	return (0);
}

int	mouse_hook(int keysym, int x, int y, t_data *d)
{
	double		factor;
	t_complex	centre;
	
	if (keysym == 4)
		factor = 0.9;
	else if (keysym == 5)
		factor = 1.1;
	else
		return (0);
	centre.r = d->fract.xmin + ((x + 0.5) / (SIZE - 1.0)) * (d->fract.xmax - d->fract.xmin);
	centre.i = d->fract.ymax - ((y + 0.5) / (SIZE - 1.0)) * (d->fract.ymax - d->fract.ymin);

	zoom_rect(&d->fract, centre, factor);
	draw_fract(d);
	return (0);
}
