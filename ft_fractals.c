/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 14:36:52 by achazal           #+#    #+#             */
/*   Updated: 2015/01/29 14:36:55 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_juliae3(int max_it, t_complex z, t_complex c)
{
	int			i;
	t_complex	tmp;
	double		x;
	double 		s;
	double 		d;
	double 		u;

	i = 0;
	tmp.real = z.real;
	tmp.imag = z.imag;
	while (i < max_it && (tmp.real * tmp.real + tmp.imag * tmp.imag) < 4)
	{
		i++;
		x = tmp.real;
		tmp.real = x * x * x - 3 * x * tmp.imag * tmp.imag;
		tmp.imag = 3 * x * x * tmp.imag - tmp.imag * tmp.imag * tmp.imag;

		s = sin(tmp.imag);
		d = cos(tmp.imag);
  		u = exp(tmp.real);
  		tmp.real = u * d + c.real;
  		tmp.imag = u * s + c.imag;
	}
	return (i);
}

int		ft_mandelbrot(int max_it, t_complex c, t_complex z)
{
	int			i;
	t_complex	tmp;
	float		x;

	(void)z;
	i = 0;
	tmp.real = 0;
	tmp.imag = 0;
	while (i < max_it && (tmp.real * tmp.real + tmp.imag * tmp.imag) < 4)
	{
		i++;
		x = tmp.real;
		tmp.real = tmp.real * tmp.real - tmp.imag * tmp.imag + c.real;
		tmp.imag = (2 * x * tmp.imag) + c.imag;
	}
	return (i);
}

void	ft_screenloop(t_env *e, t_complex z)
{
	int			i;
	int			x;
	int			y;
	t_complex	c;

	c.real = e->init.real;
	c.imag = e->init.imag;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		c.imag = e->init.imag;
		while (x < WIN_WIDTH)
		{
			i = e->fractal(e->max_it, c, z);
			ft_put_pixel(&e->buffer, x, y,
				ft_tohex(i % 360, 1, 0.5 * (i < e->max_it)));
			x++;
			c.imag += e->steps.imag;
		}
		y++;
		c.real += e->steps.real;
	}
}
