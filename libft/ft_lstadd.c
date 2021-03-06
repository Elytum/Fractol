/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:51:51 by achazal           #+#    #+#             */
/*   Updated: 2015/01/03 00:47:17 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd(t_list **alst, t_list *new)
{
	if (alst && *alst)
	{
		if (new)
			new->next = *alst;
		*alst = new;
	}
}
