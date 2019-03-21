/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 07:31:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/21 09:45:08 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_permission(t_finf const *f)
{
	if (!f || !(f->stat))
		return (-1);
	return (f->stat->st_mode);
}

static int	print_owner(int const p)
{
	write(1, ((p & S_IRUSR) ? "r" : "-"), 1);
	write(1, ((p & S_IWUSR) ? "w" : "-"), 1);
	if (p & S_IXUSR)
		write(1, (p & S_ISUID ? "s" : "x"), 1);
	else
		write(1, (p & S_ISUID ? "S" : "-"), 1);
	return (0);
}

static int	print_group(int const p)
{
	write(1, ((p & S_IRGRP) ? "r" : "-"), 1);
	write(1, ((p & S_IWGRP) ? "w" : "-"), 1);
	if (p & S_IXGRP)
		write(1, (p & S_ISGID ? "s" : "x"), 1);
	else
		write(1, (p & S_ISGID ? "S" : "-"), 1);
	return (0);
}

static int	print_other(int const p)
{
	write(1, ((p & S_IROTH) ? "r" : "-"), 1);
	write(1, ((p & S_IWOTH) ? "w" : "-"), 1);
	if (p & S_IXOTH)
		write(1, (p & S_ISVTX ? "t" : "x"), 1);
	else
		write(1, (p & S_ISVTX ? "T" : "-"), 1);
	return (0);
}

int			print_permission(t_finf const *f)
{
	char		*fn;
	char		*tmp;
	acl_t		a;
	acl_entry_t	d;
	int			p;

	IFRET(((p = get_permission(f)) < 0), -1);
	tmp = ft_strjoin(f->path, "/");
	fn = ft_strjoin(tmp, f->name);
	print_owner(p);
	print_group(p);
	print_other(p);
	a = acl_get_link_np(fn, ACL_TYPE_EXTENDED);
	if (a && acl_get_entry(a, ACL_FIRST_ENTRY, &d) == -1)
	{
		acl_free(a);
		a = NULL;
	}
	if (listxattr(fn, NULL, 0, XATTR_NOFOLLOW) > 0)
		write(1, "@", 1);
	else if (a)
		write(1, "+", 1);
	acl_free(a);
	FREE2(tmp, fn);
	return (0);
}
