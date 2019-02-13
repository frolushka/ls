/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 07:42:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/29 08:37:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	get_links_count(t_finf const *f)
{
	if (!f || !(f->stat))
		return (-1);
	return (f->stat->st_nlink);
}

int	print_links_count(t_finf const *f)
{
	char	*n;
	int		l;

	if ((l = get_links_count(f)) < 0 || !(n = ft_itoa(l)))
		return (-1);
	write(1, n, ft_strlen(n));
	return (0);
}
