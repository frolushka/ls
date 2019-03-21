/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:08:32 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/21 09:31:29 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*cur;

	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		cur = *alst;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}
