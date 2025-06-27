/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:07:20 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/06/27 10:27:45 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// void	img_pix_put(t_img *img, int x, int y, int color)
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
