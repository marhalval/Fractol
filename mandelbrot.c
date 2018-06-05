/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:25:34 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/09 18:25:37 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	run_burnmandelbrot(t_mlx *mlx, t_i p)
{
	t_complex	c[3];
	int			i;

	c[0].re = (p.x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH) + mlx->move_x;
	c[0].im = (p.y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT) + mlx->move_y;
	c[1].re = 0;
	c[1].im = 0;
	i = 0;
	while (i < mlx->maxiter && (c[1].re * c[1].re + c[1].im * c[1].im) < 4)
	{
		c[2] = c[1];
		c[1].re = c[2].re * c[2].re - c[2].im * c[2].im + c[0].re;
		c[1].im = (mlx->fractol == 2) ? 2 * c[2].re * c[2].im + c[0].im :
									fabs(2 * c[2].re * c[2].im) + c[0].im;
		i++;
	}
	if (i < mlx->maxiter)
		put_pixel(p, mlx, i, c[1]);
}

void	run_mandelbrot_3(t_mlx *mlx, t_i p)
{
	t_complex	c[3];
	int			i;

	c[0].re = (p.x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH) + mlx->move_x;
	c[0].im = (p.y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT) + mlx->move_y;
	c[1].re = 0;
	c[1].im = 0;
	i = 0;
	while (i < mlx->maxiter && (c[1].re * c[1].re + c[1].im * c[1].im) < 4)
	{
		c[2] = c[1];
		c[1].re = pow(c[2].re, 3) - 3 * c[2].re * pow(c[2].im, 2) + c[0].re;
		c[1].im = 3 * c[2].im * pow(c[2].re, 2) - pow(c[2].im, 3) + c[0].im;
		i++;
	}
	if (i < mlx->maxiter)
		put_pixel(p, mlx, i, c[1]);
}

void	run_mandelbrot_4(t_mlx *mlx, t_i p)
{
	t_complex	c[3];
	int			i;

	c[0].re = (p.x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH) + mlx->move_x;
	c[0].im = (p.y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT) + mlx->move_y;
	c[1].re = 0;
	c[1].im = 0;
	i = 0;
	while (i < mlx->maxiter && (c[1].re * c[1].re + c[1].im * c[1].im) < 4)
	{
		c[2] = c[1];
		c[1].re = pow(c[2].re, 4) + pow(c[2].im, 4) -
					6 * pow(c[2].re, 2) * pow(c[2].im, 2) + c[0].re;
		c[1].im = 4 * (pow(c[2].re, 3) * c[2].im -
					pow(c[2].im, 3) * c[2].re) + c[0].im;
		i++;
	}
	if (i < mlx->maxiter)
		put_pixel(p, mlx, i, c[1]);
}

void	run_mandelbrot_5(t_mlx *mlx, t_i p)
{
	t_complex	c[3];
	int			i;

	c[0].re = (p.x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH) + mlx->move_x;
	c[0].im = (p.y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT) + mlx->move_y;
	c[1].re = 0;
	c[1].im = 0;
	i = 0;
	while (i < mlx->maxiter && (c[1].re * c[1].re + c[1].im * c[1].im) < 4)
	{
		c[2] = c[1];
		c[1].re = pow(c[2].re, 5) - 10 * pow(c[2].re, 3) * pow(c[2].im, 2)
				+ 5 * c[2].re * pow(c[2].im, 4) + c[0].re;
		c[1].im = 5 * c[2].im * pow(c[2].re, 4) - 10 * pow(c[2].re, 2)
				* pow(c[2].im, 3) + pow(c[2].im, 5) + c[0].im;
		i++;
	}
	if (i < mlx->maxiter)
		put_pixel(p, mlx, i, c[1]);
}
