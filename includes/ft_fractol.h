/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 05:55:45 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/16 17:29:56 by ksupinsk         ###   ########.fr       */
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

# define SIZE 600
# define MAX_ITER 42

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		l_len;
	int		end;
	int		color;
}				t_img;

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_fractol
{
	char		*type;
	double		ymax;
	double		xmax;
	double		ymin;
	double		xmin;
	double		color;
	double		iteration;
	t_complex	cst;
}				t_fractol;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_fractol	fract;
}				t_data;

int			handle_keyrelease(int keysym);
int			handle_keypress(int keysym, t_data *data);
int			ft_mandelbrot(t_fractol *fract, t_complex *c);
void		img_pix_put(t_img *img, int x, int y, int color);
void		render_background(t_img *img, int color);
int			render(t_data *data);
void		ft_error(char *msg, t_data *d);
double		sq(t_complex z);
void		draw_fract(t_data *data);
void		init_mlx(t_data *data, char **argv, int argc);
void		ft_check_arg(int argc, char **argv);
void		ft_error(char *msg, t_data *d);
void		ft_clean_exit(t_data *d, int ex);
void		ft_argerror(void);
t_complex	c_new(double r, double i);
int			mouse_hook(int keysym, int x, int y, t_data *d);
void		zoom_rect(t_fractol *f, t_complex centre, double factor);
int			close_hook(t_data *d);
int			ft_julia(t_fractol *f, t_complex z);

#endif
