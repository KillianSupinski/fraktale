/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 05:55:45 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/06/24 14:06:57 by ksupinsk         ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx;
	void	*win;
}				t_data;

typedef struct s_rect
{
	int	y;
	int	x;
	int	width;
	int	height;
	int	color;
}				t_rect;

#define GREEN_PIXEL 0xFF00
#define GREEN_PIXEL 0xFF00

#endif
