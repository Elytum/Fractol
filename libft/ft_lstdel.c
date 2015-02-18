/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:44:59 by achazal           #+#    #+#             */
/*   Updated: 2015/01/03 00:44:14 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*pnext;

	ptr = *alst;
	if (alst && *alst && del)
	{
		while (ptr)
		{
			pnext = ptr->next;
			ft_lstdel(&ptr, del);
			ptr = pnext;
		}
		ft_lstdelone(alst, del);
	}
}
