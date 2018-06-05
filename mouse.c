/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:25:11 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/09 18:25:14 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && mlx->lock == 1)
	{
		mlx->q.re = (x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH) + mlx->move_x;
		mlx->q.im = (y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT) + mlx->move_y;
	}
	run_fractal(mlx);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5)
	{
		mlx->zoom *= 2;
		mlx->move_x += (x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH);
		mlx->move_y += (y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT);
	}
	if (button == 4)
	{
		mlx->move_x -= (x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH);
		mlx->move_y -= (y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT);
		mlx->zoom *= 0.5;
	}
	run_fractal(mlx);
	return (0);
}
