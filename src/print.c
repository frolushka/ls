/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 04:03:53 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/29 11:02:58 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	print_table(t_finf const *f)
{
	print_type(f);
	print_permission(f);
	write(1, "\t", 1);
	print_links_count(f);
	write(1, "\t", 1);
	print_owner_name(f);
	write(1, "\t", 1);
	print_group_name(f);
	write(1, "\t", 1);
	print_size(f);
	write(1, "\t", 1);
	print_data(f);
	write(1, "\t", 1);
	print_name(f);
	write(1, "\n", 1);
	return (0);
}

int	print_simple(t_finf const *f)
{
	print_name(f);
	write(1, "\t", 1);
	return (0);
}
