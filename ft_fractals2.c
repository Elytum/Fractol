
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractals2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 14:36:52 by achazal           #+#    #+#             */
/*   Updated: 2015/01/29 14:36:55 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_fractoil(int max_it, t_complex z, t_complex c)
{
	int			i;
	t_complex	tmp;
	double		x;

	i = 0;
	tmp.real = z.real;
	tmp.imag = z.imag;
	while (i < max_it && (pow(tmp.real, 2) + tmp.imag * tmp.imag) < 4)
	{
		i++;
		x = tmp.real;
		tmp.real = (tmp.real + c.real - tmp.imag + c.imag) / 2;
		tmp.imag = x * 2 * (tmp.imag + tmp.imag + c.real - tmp.real) / 2;
	}
	return (i);
}

int		ft_dragon(int max_it, t_complex z, t_complex c)
{
	int			i;
	t_complex	a;
	float		x;

	(void)z;
	i = 0;
	a.real = z.real;
	a.imag = z.imag;
	while (i < max_it && (a.real * a.real + a.imag * a.imag) < 4)
	{
		i++;
		x = a.real;
		a.real = a.real * a.real * a.real -
			(3 * a.real * a.imag * a.imag) + c.real;
		a.imag = (3 * x * x * a.imag) + c.imag;
	}
	return (i);
}

int		ft_julia(int max_it, t_complex z, t_complex c)
{
	int			i;
	t_complex	tmp;
	double		x;

	i = 0;
	tmp.real = z.real;
	tmp.imag = z.imag;
	while (i < max_it && (tmp.real * tmp.real + tmp.imag * tmp.imag) < 4)
	{
		i++;
		x = tmp.real;
		tmp.real = tmp.real * tmp.real - tmp.imag * tmp.imag + c.real;
		tmp.imag = (2 * x * tmp.imag) + c.imag;
	}
	return (i);
}

int		ft_julia3(int max_it, t_complex z, t_complex c)
{
	int			i;
	t_complex	tmp;
	double		x;

	i = 0;
	tmp.real = z.real;
	tmp.imag = z.imag;
	while (i < max_it && (tmp.real * tmp.real + tmp.imag * tmp.imag) < 4)
	{
		i++;
		x = tmp.real;
		tmp.real = x * x * x - 3 * x * tmp.imag * tmp.imag + c.real;
		tmp.imag = 3 * x * x * tmp.imag - tmp.imag * tmp.imag * tmp.imag + c.imag;
	}
	return (i);
}

int		ft_julia4(int max_it, t_complex z, t_complex c)
{
	int			i;
	t_complex	tmp;
	double		x;

	i = 0;
	tmp.real = z.real;
	tmp.imag = z.imag;
	while (i < max_it && (tmp.real * tmp.real + tmp.imag * tmp.imag) < 4)
	{
		i++;
		x = tmp.real;
		tmp.real = tmp.real * tmp.real - tmp.imag * tmp.imag;
		tmp.imag = (2 * x * tmp.imag);
		tmp.real = tmp.real * tmp.real - tmp.imag * tmp.imag + c.real;
		tmp.imag = (2 * x * tmp.imag) + c.imag;
	}
	return (i);
}