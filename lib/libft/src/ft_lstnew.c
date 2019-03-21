/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:05:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/21 05:58:36 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;
	char	*tmp;

	if (!(res = (t_list *)malloc(sizeof(*res))))
		return (NULL);
	if (!content)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		tmp = (char *)content;
		res->content = (void *)tmp;
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
