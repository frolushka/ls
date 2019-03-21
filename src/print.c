/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 04:03:53 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/21 10:51:47 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	prepare_helper(t_list *root, const char *fn, int flags, int i)
{
	char	*tmp;

	if ((i != 0 && !(flags & FLAG_L) && (flags & FLAG_MULT || flags & FLAG_R)))
		write(1, "\n", 1);
	if (flags & FLAG_MULT || (flags & FLAG_R && ft_strcmp(fn, ".") != 0))
		print4(fn, ":\n", "", "");
	if (flags & FLAG_L)
	{
		tmp = ft_itoa(count_blocks(root, flags));
		print4("total ", tmp, "\n", "");
		free(tmp);
	}
}

int		print_table(t_finf const *f, int flags, t_tblp *tbl)
{
	int	i;

	i = -1;
	print_type(f);
	print_permission(f);
	write(1, "\t", 1);
	print_links_count(f);
	write(1, "\t", 1);
	print_owner_name(f);
	while (++i < tbl->owname - get_owner_tabs(f) + 1)
		write(1, "\t", 1);
	print_group_name(f);
	i = -1;
	while (++i < tbl->grname - get_group_tabs(f) + 1)
		write(1, "\t", 1);
	print_size(f);
	i = -1;
	while (++i < tbl->size - get_size_tabs(f) + 1)
		write(1, "\t", 1);
	print_data(f);
	write(1, "\t", 1);
	print_name(f, flags);
	write(1, "\n", 1);
	return (0);
}

int		print_simple(t_finf const *f, int flags)
{
	print_name(f, flags);
	write(1, "\t", 1);
	return (0);
}
