/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 08:06:13 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/21 14:59:10 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_name(t_finf const *f, int flags)
{
	int		t;
	char	*n;
	char	*tmp;
	char	buf[MAXNAMLEN];

	t = get_type(f);
	ft_bzero(buf, MAXNAMLEN);
	if (!f)
		return (NULL);
	if (t == DT_LNK && flags & FLAG_L)
	{
		tmp = ft_strjoin(f->path, "/");
		n = ft_strjoin(tmp, f->name);
		free(tmp);
		readlink(n, buf, MAXNAMLEN);
		free(n);
		tmp = ft_strjoin(" -> ", buf);
		n = ft_strjoin(f->name, tmp);
		free(tmp);
	}
	else
		n = strdup(f->name);
	return (n);
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

int			print_name(t_finf const *f, int flags)
{
	char	*n;

	if (!(n = get_name(f, flags)))
		return (-1);
	set_colors_add(f);
	write(1, n, ft_strlen(n));
	write(1, "\033[0m", 5);
	free(n);
	return (0);
}
