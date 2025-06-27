/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 05:55:45 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/06/28 01:27:44 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libx/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_data;

typedef struct s_rect
{
	int	y;
	int	x;
	int	width;
	int	height;
	int	color;
}				t_rect;

int		handle_keyrelease(int keysym);
int		handle_keypress(int keysym, t_data *data);

int		render_rect(t_img *img, t_rect rect);
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);
int		render(t_data *data);
void	ft_error(char *msg, t_data *d);

#endif
