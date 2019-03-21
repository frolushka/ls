/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_finf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:24:59 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/21 09:35:31 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_finf	*init_finf(const char *path, const t_dir *dir, const int flags)
{
	t_finf	*res;
	char	*full_path;
	char	*path1;
	t_stat	*stas;

	if (!(res = (t_finf *)malloc(sizeof(t_finf))))
		return (NULL);
	res->dir = (t_dir *)dir;
	res->path = (char *)path;
	if (flags & (FLAG_L | FLAG_T))
	{
		if ((stas = (t_stat *)malloc(sizeof(t_stat))))
		{
			path1 = ft_strjoin(path, "/");
			full_path = ft_strjoin(path1, dir->d_name);
			lstat(full_path, stas);
			res->stat = stas;
			free(full_path);
			free(path1);
		}
	}
	else
		res->stat = NULL;
	res->name = ft_strdup((char *)dir->d_name);
	return (res);
}

t_finf	*init_finf_dir(const char *path)
{
	t_finf	*res;
	t_stat	*stas;

	if (!(res = (t_finf *)malloc(sizeof(t_finf))))
		return (NULL);
	res->path = (char *)path;
	if ((stas = (t_stat *)malloc(sizeof(t_stat))))
	{
		lstat(path, stas);
		res->stat = stas;
	}
	else
		res->stat = NULL;
	res->name = ft_strdup((char *)path);
	return (res);
}
