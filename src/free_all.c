/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 04:34:58 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/21 07:04:21 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	lstdelones(t_list **alst, const char *fn)
{
	t_finf *f;

	if (!alst || !*alst)
		return ;
	f = (t_finf *)((*alst)->content);
	if (f->name && *f->name)
		free(f->name);
	if (f->path && *f->path && strcmp(f->path, fn) != 0)
		free(f->path);
	if (f->stat)
		free(f->stat);
	free((*alst)->content);
	free(*alst);
	*alst = NULL;
}

void		lstdels(t_list **alst, const char *fn)
{
	if (!alst || !(*alst))
		return ;
	if ((*alst)->next)
		lstdels(&((*alst)->next), fn);
	lstdelones(alst, fn);
}

void		free_tinf(t_finf **alst, const char *fn)
{
	t_finf *f;

	if (!alst || !*alst)
		return ;
	f = (*alst);
	if (f->name && *f->name)
		free(f->name);
	if (f->path && *f->path && strcmp(f->path, fn) != 0)
		free(f->path);
	if (f->stat)
		free(f->stat);
	free(*alst);
	*alst = NULL;
}
