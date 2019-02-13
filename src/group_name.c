/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 07:57:12 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/29 08:36:40 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_group_name(t_finf const *f)
{
	struct group	*gr;

	if (!f || !(f->stat))
		return (NULL);
	gr = getgrgid(f->stat->st_gid);
	if (!gr)
		return (NULL);
	return (gr->gr_name);
}

int		print_group_name(t_finf const *f)
{
	char	*name;

	if (!(name = get_group_name(f)))
		return (-1);
	write(1, name, ft_strlen(name));
	return (0);
}
