/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 08:05:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/29 11:20:54 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_data(t_finf const *f)
{
	if (!f || !(f->stat))
		return (NULL);
	return (ctime(&f->stat->st_mtimespec.tv_sec));
}

int	print_data(t_finf const *f)
{
	char	*n;
	int		c;

	if (!(n = get_data(f)))
		return (-1);
	c = (int)time(NULL);
	write(1, n + 4, ft_strlen(n) - 19);
	write(1, " ", 1);
	if (labs(c - f->stat->st_mtimespec.tv_sec) > HALF_YEAR)
		write(1, n + 20, 4);
	else
		write(1, n + 11, 5);
	return (0);
}
