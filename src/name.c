/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 08:06:13 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/04 02:10:39 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_name(t_finf const *f)
{
	if (!f || !(f->dir))
		return (NULL);
	return (f->dir->d_name);
}

static void	set_colors_add(t_finf const *f)
{
	int	t;
	int	p;

	t = get_type(f);
	p = get_permission(f);
	(p & S_IWOTH && p & S_ISVTX ? write(1, "\033[30;42m", 8) : 0);
	(p & S_IWOTH && !(p & S_ISVTX) ? write(1, "\033[30;43m", 8) : 0);
	if (p & (S_IXUSR | S_IXGRP | S_IXOTH))
	{
		(p & S_ISUID ? write(1, "\033[30;41m", 8) : 0);
		(p & S_ISGID ? write(1, "\033[30;46m", 8) : 0);
		(!(p & S_ISUID || p & S_ISGID) ? write(1, "\033[31m", 5) : 0);
	}
	(t == DT_DIR ? write(1, "\033[34m", 5) : 0);
	(t == DT_LNK ? write(1, "\033[35m", 5) : 0);
	(t == DT_SOCK ? write(1, "\033[32m", 5) : 0);
	(t == DT_FIFO ? write(1, "\033[33m", 5) : 0);
	(t == DT_BLK ? write(1, "\033[34;46m", 8) : 0);
	(t == DT_CHR ? write(1, "\033[34;43m", 8) : 0);
}

int	print_name(t_finf const *f)
{
	char	*n;

	if (!(n = get_name(f)))
		return (-1);
	set_colors_add(f);
	write(1, n, ft_strlen(n));
	write(1, "\033[0m", 5);
	return (0);
}
