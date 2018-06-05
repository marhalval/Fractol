/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flows.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 19:49:38 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/03 19:49:43 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_fractal(t_mlx *mlx, t_i p)
{
	if (mlx->fractol == 1 || mlx->fractol == 2)
		run_burnmandelbrot(mlx, p);
	else if (mlx->fractol == 3)
		run_mandelbrot_3(mlx, p);
	else if (mlx->fractol == 4)
		run_mandelbrot_4(mlx, p);
	else if (mlx->fractol == 5)
		run_mandelbrot_5(mlx, p);
	else if (mlx->fractol == 6)
		run_julia(mlx, p);
	else if (mlx->fractol == 7)
		run_julia_3(mlx, p);
	else if (mlx->fractol == 8)
		run_julia_4(mlx, p);
	else if (mlx->fractol == 9)
		run_julia_5(mlx, p);
}

void	*run_flow(void *thread)
{
	t_flow		*flow;
	t_i			p;
	int			len;

	flow = (t_flow*)thread;
	p.y = flow->y;
	len = HEIGHT / flow->mlx->flows_num + flow->y;
	while (p.y < len)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			choose_fractal(flow->mlx, p);
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

void	make_flows(t_mlx *mlx)
{
	int			i;
	pthread_t	thread[mlx->flows_num];
	t_flow		flow[mlx->flows_num];

	i = 0;
	while (i < mlx->flows_num)
	{
		flow[i].y = i * HEIGHT / mlx->flows_num;
		flow[i].mlx = mlx;
		pthread_create(&thread[i], NULL, run_flow, (void*)&flow[i]);
		i++;
	}
	i = 0;
	while (i < mlx->flows_num)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}

void	run_fractal(t_mlx *mlx)
{
	t_complex	c[3];
	int			i;

	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size, &mlx->endi);
	make_flows(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, 5, 1, 16777215, ft_itoa(mlx->maxiter));
	mlx_destroy_image(mlx->mlx, mlx->img);
}
