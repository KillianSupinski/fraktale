/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:07:20 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/10 12:01:21 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	calc_fract(t_fractol *fract, t_complex *c)
{
	int	iter;

	iter = 0;
	if (ft_strcmp(fract->type, "mandelbrot") == 0)
		iter = ft_mandelbrot(fract, c);
	return (iter);
}

void	set_pixel(t_img *img, int x, int y, int rgb)
{
	char	*dst;

	if (x < 0 || y < 0 || x > SIZE || y > SIZE)
		return ;
	dst = img->addr + y * img->l_len + x * (img->bpp >> 3);
	*(unsigned int *)dst = rgb;
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
			fract.color = set_color(iter, MAX_ITER);
			set_pixel(&data->img, x, y, fract.color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}
// {
//     char    *pixel;
//
//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
//     *(int *)pixel = color;
// }
//
// int	render_rect(t_img *img, t_rect rect)
// {
// 	int	i;
// 	int	j;
//
// 	i = rect.y;
// 	while (i < rect.y + rect.height)
// 	{
// 		j = rect.x;
// 		while (j < rect.x + rect.width)
// 			img_pix_put(img, j++, i, rect.color);
// 		i++;
// 	}
// 	return (0);
// }
//
// void	render_background(t_img *img, int color)
// {
//     int	i;
//     int	j;
//
//     i = 0;
//     while (i < WINDOW_HEIGHT)
//     {
//         j = 0;
//         while (j < WINDOW_WIDTH)
//         {
//             img_pix_put(img, j++, i, color);
//         }
//         ++i;
//     }
// }
//
// int	render(t_data *data)
// {
// 	if (data->win == NULL)
// 		return (1);
// 	render_background(&data->img, WHITE_PIXEL);
//     render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
//             100, 100, GREEN_PIXEL});
//     render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
// 	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
//     return (0);
// }
