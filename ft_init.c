/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 14:37:14 by achazal           #+#    #+#             */
/*   Updated: 2015/01/29 14:37:15 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init(t_env *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
		ft_error("Failed to init mlx.");
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	if (ft_strequ("mandelbrot", e->name))
		ft_init_mandelbrot(e);
	else if (ft_strequ("julia", e->name))
		ft_init_julia(e);
	else if (ft_strequ("julia3", e->name))
		ft_init_julia3(e);
	else if (ft_strequ("julia4", e->name))
		ft_init_julia4(e);
	else if (ft_strequ("juliae3", e->name))
		ft_init_juliae3(e);
	else if (ft_strequ("fractoil", e->name))
		ft_init_fractoil(e);
	else if (ft_strequ("dragon", e->name))
		ft_init_dragon(e);
	e->buffer.img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->buffer.data = mlx_get_data_addr(e->buffer.img, &e->buffer.bpp,
			&e->buffer.line_size, &e->buffer.endian);
	e->pastpos.imag = 0;
	e->pastpos.real = 0;
	e->mouse.real = WIN_WIDTH / 2;
	e->mouse.imag = WIN_HEIGHT / 2;
}

int			expose_hook(t_env *e)
{
	ft_screenloop(e, e->z);
	mlx_put_image_to_window(e->mlx, e->win, e->buffer.img, 0, 0);
	return (0);
}

int			mousemotion(int x, int y, t_env *e)
{
	e->mouse.imag = x;
	e->mouse.real = y;
	e->z.imag += (x - e->pastpos.imag) / WIN_WIDTH * e->steps.imag * 500;
	e->z.real += (y - e->pastpos.real) / WIN_HEIGHT * e->steps.real * 500;
	e->pastpos.imag = x;
	e->pastpos.real = y;
	e->update = 1;
	return (0);
}

int			ft_refresh(t_env *e)
{
	if (e->update)
	{
		ft_setinit(e);
		ft_screenloop(e, e->z);
		mlx_put_image_to_window(e->mlx, e->win, e->buffer.img, 0, 0);
		e->update = 0;
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
		ft_error("Fractal: mandelbrot, dragon, julia(3/4/e) or fractoil.");
	if (!(ft_strequ("mandelbrot", av[1]) || ft_strequ("dragon", av[1]) ||
		ft_strequ("julia", av[1]) || ft_strequ("julia3", av[1]) || 
		ft_strequ("julia4", av[1]) || ft_strequ("fractoil", av[1]) ||
		ft_strequ("juliae3", av[1])))
		ft_error("Fractal: mandelbrot, dragon, julia(3/4/e) or fractoil.");
	e = (t_env *)ft_memalloc(sizeof(t_env));
	e->name = av[1];
	ft_init(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, keyboard_event, e);
	mlx_hook(e->win, MotionNotify, PointerMotionMask, &mousemotion, e);
	mlx_hook(e->win, ButtonPress, ButtonPressMask, &mouse_event, e);
	mlx_loop_hook(e->mlx, &ft_refresh, e);
	mlx_loop(e->mlx);
	return (0);
}
