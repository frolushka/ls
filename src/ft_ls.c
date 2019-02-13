/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 20:57:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/30 17:59:51 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*read_list(char const *fn, const int flags, DIR **d)
{
	t_list	*res;
	DIR		*dirp;
	t_dir	*dir;

	if (!(dirp = opendir(fn)))
		return (NULL);
	res = NULL;
	while ((dir = readdir(dirp)) != NULL)
		if (!res)
			res = ft_lstnew((void *)init_finf(fn, dir, flags), sizeof(*dir));
		else
			lst_insert_new(fn, flags, dir, &res);
	*d = dirp;
	return (res);
}

// static int		count_blocks(t_list *cur, long bs)
// {
// 	int res;

// 	res = 0;
// 	while (cur)
// 	{
// 		res += (int)((t_finf *)(cur->content))->stat->st_size * 512 / bs;
// 		cur = cur->next;
// 	}
// 	return (res);
// }

static int		print_dir(char const *fn, int flags)
{
	t_list	*root;
	t_list	*cur;
	DIR		*dirp;
	t_dir	*dir;

	// if (!(dirp = opendir(fn)))
	// 	return (-1);
	// root = NULL;
	// while ((dir = readdir(dirp)) != NULL)
	// 	(!root ? root = ft_lstnew((void *)dir, sizeof(*dir)) :
	// 		// ft_lstadd_back(&root, ft_lstnew((void *)dir, sizeof(*dir))));
	// 		ft_lstinsert(&root, ft_lstnew((void *)dir, sizeof(*dir)), &comp_dirs_simple));
	root = read_list(fn, flags, &dirp);
	if ((flags & FLAG_mult || flags & FLAG_R) && ft_strcmp(fn, ".") != 0)
		print4(fn, ":\n", "", "");
	// print4("total ", ft_itoa(count_blocks(root, ((t_finf *)(root->content))->stat->st_blksize)), "\n", "");
	cur = root;
	while (cur)
	{
		dir = ((t_finf *)(cur->content))->dir;
		if (!(flags & FLAG_mult) && ((dir->d_name[0] == '.' && dir->d_name[1] == '\0') ||
			(dir->d_name[0] == '.' && dir->d_name[1] == '.'&& dir->d_name[2] == '\0')))
			(flags & FLAG_a ? print4(dir->d_name, "\t", "", "") : 0);
		else
			(flags & FLAG_l ? print_table((t_finf *)(cur->content)) : print_simple((t_finf *)(cur->content)));
			// print4(dir->d_name, "\t", "", "");
		cur = cur->next;
	}
	write(1, "\n", 1);
	ft_lstdels(&root);
	closedir(dirp);
	return (0);
}

static int		recurse_ls(char const *fn, int flags)
{
	DIR		*dirp;
	t_dir	*dir;

	if (!(dirp = opendir(fn)))
		return (-1);
	while ((dir = readdir(dirp)) != NULL)
	{
		if (dir->d_type == 4 && ft_strcmp(dir->d_name, ".") != 0 && ft_strcmp(dir->d_name, "..") != 0)
			ft_ls(ft_strjoin(ft_strjoin(fn, "/"), dir->d_name), flags);
	}
	closedir(dirp);
	return (0);
}

int				ft_ls(char const *fn, int flags)
{
	print_dir(fn, flags);
	if (flags & FLAG_R)
		recurse_ls(fn, flags);
	return (0);
}
