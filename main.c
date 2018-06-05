/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:34:28 by hvashchu          #+#    #+#             */
/*   Updated: 2017/09/26 20:34:31 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putendl("Usage: ./fractol [number]");
	ft_putendl("max 2 params for input");
	ft_putendl("[1] - Burning Ship");
	ft_putendl("[2] - Maldebrot");
	ft_putendl("[3] - Maldebrot^3");
	ft_putendl("[4] - Maldebrot^4");
	ft_putendl("[5] - Maldebrot^5");
	ft_putendl("[6] - Julia");
	ft_putendl("[7] - Julia_3");
	ft_putendl("[8] - Julia_4");
	ft_putendl("[9] - Julia_5");
	exit(0);
}

int		expose_hook(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int		exit_mouse(void)
{
	exit(0);
}

void	check(char *str, int i)
{
	if (ft_atoi(str) < 1 || ft_atoi(str) > 9)
	{
		ft_putnbr(i);
		ft_putendl(" param is not valid");
		usage();
	}
}

int		main(int argc, char **argv)
{
	t_mlx	*new;
	int		i;

	i = 1;
	while (i < argc - 1 && (argc > 1 && argc < 4))
	{
		if (fork() == 0)
			break ;
		i++;
	}
	if (argc == 1 || argc > 3)
		usage();
	check(argv[i], i);
	new = ft_memalloc(sizeof(t_mlx));
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, WIDTH, HEIGHT, "fractol");
	init_param(new, argv[i]);
	run_fractal(new);
	mlx_mouse_hook(new->win, mouse_hook, new);
	mlx_expose_hook(new->win, expose_hook, new);
	mlx_hook(new->win, 17, 1L << 17, exit_mouse, new);
	mlx_hook(new->win, 6, 0, mouse_move, new);
	mlx_hook(new->win, 2, 5, key_hook, new);
	mlx_loop(new->mlx);
	return (0);
}
