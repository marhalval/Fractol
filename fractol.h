/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:34:42 by hvashchu          #+#    #+#             */
/*   Updated: 2017/09/26 20:34:44 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <pthread.h>
# define WIDTH 800
# define HEIGHT 800

typedef	struct	s_i
{
	int				x;
	int				y;
}				t_i;

typedef	struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size;
	int			endi;
	int			fractol;
	double		zoom;
	double		move_x;
	double		move_y;
	int			maxiter;
	int			lock;
	int			palette;
	double		frq[3];
	double		phase[3];
	int			amp[3];
	int			center[3];
	int			flows_num;
	t_complex	q;
}				t_mlx;

typedef	struct	s_flow
{
	int			y;
	t_mlx		*mlx;
}				t_flow;

void			make_flows(t_mlx *mlx);
void			*run_flow(void *thread);
void			init_param(t_mlx *mlx, char *str);
void			choose_fractal(t_mlx *mlx, t_i p);
void			run_fractal(t_mlx *mlx);
void			run_julia(t_mlx *mlx, t_i p);
void			run_julia_3(t_mlx *mlx, t_i p);
void			run_julia_4(t_mlx *mlx, t_i p);
void			run_julia_5(t_mlx *mlx, t_i p);
void			run_burnmandelbrot(t_mlx *mlx, t_i p);
void			run_mandelbrot_3(t_mlx *mlx, t_i p);
void			run_mandelbrot_4(t_mlx *mlx, t_i p);
void			run_mandelbrot_5(t_mlx *mlx, t_i p);
void			put_pixel(t_i p, t_mlx *mlx, int i, t_complex z);
int				key_hook(int keykode, t_mlx *mlx);
int				key_hook_color(int keycode, t_mlx *mlx);
int				mouse_hook(int button, int x, int y, t_mlx *mlx);
int				mouse_move(int x, int y, t_mlx *mlx);

#endif
