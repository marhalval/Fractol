/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 20:20:12 by hvashchu          #+#    #+#             */
/*   Updated: 2017/09/27 20:20:14 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_put_pixel(t_mlx *mlx, int i, double n)
{
	if (mlx->palette == 2)
	{
		mlx->data[i] = (unsigned char)(sin(0.2 * n) * 67 + 183);
		mlx->data[i + 1] = (unsigned char)(sin(0.2 * n) * 92 + 158);
		mlx->data[i + 2] = (unsigned char)(sin(0.3 * n) * 47 + 168);
	}
	else if (mlx->palette == 3)
	{
		mlx->data[i] = (unsigned char)(sin(0.3 * n + 0) * 127 + 128);
		mlx->data[i + 1] = (unsigned char)(sin(0.3 * n + 2) * 127 + 128);
		mlx->data[i + 2] = (unsigned char)(sin(0.3 * n + 4) * 127 + 128);
	}
	else
	{
		mlx->data[i] = (unsigned char)(sin(-0.3 * n - 1) * 127 + 128);
		mlx->data[i + 1] = (unsigned char)(sin(-0.3 * n - 1) * 127 + 128);
		mlx->data[i + 2] = (unsigned char)(sin(-0.3 * n - 1) * 127 + 128);
	}
}

void	put_pixel(t_i p, t_mlx *mlx, int index, t_complex z)
{
	double	n;
	double	mod;
	int		i;

	mod = sqrt(z.re * z.re + z.im * z.im);
	n = index + 1 - log(log(mod) / log(2)) / log(2);
	if (p.x >= 0 && p.x <= WIDTH && p.y >= 0 && p.y <= HEIGHT)
	{
		i = (p.y) * mlx->size + (p.x) * 4;
		if (mlx->palette == 1)
		{
			mlx->data[i] = (unsigned char)(sin(mlx->frq[0] * n + mlx->phase[0])
							* mlx->amp[0] + mlx->center[0]);
			mlx->data[i + 1] = (unsigned char)(sin(mlx->frq[1] * n +
							mlx->phase[1]) * mlx->amp[1] + mlx->center[1]);
			mlx->data[i + 2] = (unsigned char)(sin(mlx->frq[2] * n +
							mlx->phase[2]) * mlx->amp[2] + mlx->center[2]);
		}
		else
			help_put_pixel(mlx, i, n);
	}
}

void	init_param(t_mlx *mlx, char *str)
{
	mlx->flows_num = 10;
	mlx->maxiter = 30;
	mlx->zoom = 0.6;
	mlx->lock = 1;
	mlx->palette = 1;
	mlx->fractol = ft_atoi(str);
	mlx->frq[0] = 0.3;
	mlx->phase[0] = 1;
	mlx->amp[0] = 127;
	mlx->center[0] = 128;
	mlx->frq[1] = 0.3;
	mlx->phase[1] = 2;
	mlx->amp[1] = 127;
	mlx->center[1] = 128;
	mlx->frq[2] = 0.3;
	mlx->phase[2] = 3;
	mlx->amp[2] = 127;
	mlx->center[2] = 128;
	if (mlx->fractol == 2)
		mlx->move_x = -0.5;
	else if (mlx->fractol == 1)
	{
		mlx->move_x = -0.4;
		mlx->move_y = -0.5;
	}
}
