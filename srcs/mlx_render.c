/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:07:20 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/27 16:36:51 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	calc_fract(t_fractol *fract, t_complex *c)
{
	int	iter;

	iter = 0;
	if (ft_strcmp(fract->type, "mandelbrot") == 0)
		iter = ft_mandelbrot(fract, c);
	if (ft_strcmp(fract->type, "julia") == 0)
		iter = ft_julia(fract, *c);
	return (iter);
}

void	set_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > SIZE || y > SIZE)
		return ;
	dst = img->addr + y * img->l_len + x * (img->bpp >> 3);
	*(unsigned int *)dst = color;
}

int	set_color(int iter, int max)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max)
		return (0x000000);
	t = (double)iter / max;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

void	draw_fract(t_data *data)
{
	t_fractol	fract;
	t_complex	c;
	int			x;
	int			y;
	int			iter;

	x = -1;
	fract = data->fract;
	while (++x < SIZE)
	{
		y = -1;
		while (++y < SIZE)
		{
			c.r = fract.xmin + (double)x / SIZE * (fract.xmax - fract.xmin);
			c.i = fract.ymax - (double)y / SIZE * (fract.ymax - fract.ymin);
			iter = calc_fract(&fract, &c);
			fract.color = set_color(iter, fract.iteration);
			set_pixel(&data->img, x, y, fract.color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}
