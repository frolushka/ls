/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   owner_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 07:48:12 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/21 09:28:12 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_owner_name(t_finf const *f)
{
	struct passwd	*pw;

	if (!f || !(f->stat))
		return (NULL);
	pw = getpwuid(f->stat->st_uid);
	if (!pw)
		return (NULL);
	return (pw->pw_name);
}

int		print_owner_name(t_finf const *f)
{
	char	*name;

	if (!(name = get_owner_name(f)))
		return (-1);
	write(1, name, ft_strlen(name));
	return (0);
}

int		get_owner_tabs(t_finf const *f)
{
	char	*name;

	if (!(name = get_owner_name(f)))
		return (-1);
	return (ft_strlen(name) / 8 + 1);
}
