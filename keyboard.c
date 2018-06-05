/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:25:20 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/09 18:25:22 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_palette2(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		mlx->frq[0] += 0.1;
	if (keycode == 14)
		mlx->phase[0] -= 1;
	if (keycode == 15)
		mlx->phase[0] += 1;
	if (keycode == 17)
		mlx->amp[0] -= 5;
	if (keycode == 16)
		mlx->amp[0] += 5;
	if (keycode == 45)
		mlx->amp[2] += 5;
	if (keycode == 32)
		mlx->center[0] -= 5;
	if (keycode == 34)
		mlx->center[0] += 5;
	if (keycode == 38)
		mlx->center[1] -= 5;
	if (keycode == 40)
		mlx->center[1] += 5;
	if (keycode == 46)
		mlx->center[2] -= 5;
	if (keycode == 43)
		mlx->center[2] += 5;
}

void	key_palette1(int keycode, t_mlx *mlx)
{
	if (keycode == 12)
		mlx->frq[0] -= 0.1;
	if (keycode == 0)
		mlx->frq[1] -= 0.1;
	if (keycode == 1)
		mlx->frq[1] += 0.1;
	if (keycode == 6)
		mlx->frq[2] -= 0.1;
	if (keycode == 7)
		mlx->frq[2] += 0.1;
	if (keycode == 2)
		mlx->phase[1] -= 1;
	if (keycode == 3)
		mlx->phase[1] += 1;
	if (keycode == 8)
		mlx->phase[2] -= 1;
	if (keycode == 9)
		mlx->phase[2] += 1;
	if (keycode == 5)
		mlx->amp[1] -= 5;
	if (keycode == 4)
		mlx->amp[1] += 5;
	if (keycode == 11)
		mlx->amp[2] -= 5;
}

void	key_palette(int keycode, t_mlx *mlx)
{
	if (keycode <= 12)
		key_palette1(keycode, mlx);
	else
		key_palette2(keycode, mlx);
}

void	key_color_power(int keycode, t_mlx *mlx)
{
	if (keycode == 36)
	{
		if (mlx->palette == 1)
			mlx->palette++;
		else if (mlx->palette == 2)
			mlx->palette++;
		else if (mlx->palette == 3)
			mlx->palette++;
		else
			mlx->palette = 1;
	}
	if (keycode >= 19 && keycode <= 23 && mlx->fractol != 1)
	{
		if (keycode == 19)
			mlx->fractol = (mlx->fractol >= 2 && mlx->fractol <= 5) ? 2 : 6;
		if (keycode == 20)
			mlx->fractol = (mlx->fractol >= 2 && mlx->fractol <= 5) ? 3 : 7;
		if (keycode == 21)
			mlx->fractol = (mlx->fractol >= 2 && mlx->fractol <= 5) ? 4 : 8;
		if (keycode == 23)
			mlx->fractol = (mlx->fractol >= 2 && mlx->fractol <= 5) ? 5 : 9;
	}
}

int		key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (mlx->palette == 1)
		key_palette(keycode, mlx);
	if (keycode == 49)
		mlx->lock = (mlx->lock == 1) ? 0 : 1;
	if (keycode == 126)
		mlx->move_y -= 0.1 / mlx->zoom;
	if (keycode == 125)
		mlx->move_y += 0.1 / mlx->zoom;
	if (keycode == 124)
		mlx->move_x += 0.1 / mlx->zoom;
	if (keycode == 123)
		mlx->move_x -= 0.1 / mlx->zoom;
	if (keycode == 24)
		mlx->maxiter++;
	if (keycode == 27)
		mlx->maxiter--;
	if ((keycode >= 19 && keycode <= 23) || keycode == 36)
		key_color_power(keycode, mlx);
	run_fractal(mlx);
	return (0);
}
