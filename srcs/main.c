/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 08:45:56 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/06/24 16:07:41 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

// void	MLX_ERROR(t_data *data)
// {
// 	ft_printf("Error");
// }

#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 1080

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000

int	handle_no_event(void *data)
{
	if (!data)
		return (0);
	return (0);
}
int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

int	handle_keyrelease(int keysym)
{
    printf("Keyrelease: %d\n", keysym);
    return (0);
}


int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->win == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx, data->win, j++, i, rect.color);
		i++;
	}
	return (0);
}
int	render(t_data *data)
{
    render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
            100, 100, GREEN_PIXEL});
    render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});

    return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	if(argc > 2)
		return (0);
	if (!argv)
		return (0);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.win = mlx_new_window(data.mlx, 1080, 720, "OK MLX");
	if (data.win == NULL)
	{
		free(data.win);
		return (0);
	}
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
