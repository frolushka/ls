/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 20:57:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/21 19:12:46 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*read_list(char const *fn, const int flags)
{
	t_list	*res;
	DIR		*dirp;
	t_dir	*dir;

	if (!(dirp = opendir(fn)))
		return (NULL);
	res = NULL;
	while ((dir = readdir(dirp)) != NULL)
		if (!res)
			res = ft_lstnew((void *)init_finf(fn, dir, flags), sizeof(t_finf));
		else
			lst_insert_new(fn, flags, dir, &res);
	closedir(dirp);
	return (res);
}

int				count_blocks(t_list *cur, int flags)
{
	int res;

	res = 0;
	while (cur)
	{
		if (((t_finf *)(cur->content))->name[0] == '.' && !(flags & FLAG_A))
		{
			cur = cur->next;
			continue ;
		}
		res += (int)((t_finf *)(cur->content))->stat->st_blocks;
		cur = cur->next;
	}
	return (res);
}

static int		print_dir(char const *fn, int flags, int i, int *file_c)
{
	t_list	*root;
	t_list	*cur;
	t_tblp	tbl;

	root = read_list(fn, flags);
	fill_tbl(root, &tbl);
	if (*file_c > 0 && !(*file_c = 0))
		write(1, "\n", 1);
	prepare_helper(root, fn, flags, i);
	cur = root;
	while (cur)
	{
		if (((t_finf *)(cur->content))->name[0] == '.' && !(flags & FLAG_A))
		{
			cur = cur->next;
			continue ;
		}
		(flags & FLAG_L ? print_table((t_finf *)(cur->content), flags, &tbl)
			: print_simple((t_finf *)(cur->content), flags));
		cur = cur->next;
	}
	lstdels(&root, fn);
	return (0);
}

static int		recurse_ls(char const *fn, int flags)
{
	DIR		*dirp;
	t_dir	*dir;
	char	*tmp;
	char	*tmp2;

	if (!(dirp = opendir(fn)))
		return (-1);
	while ((dir = readdir(dirp)) != NULL)
		if (dir->d_type == 4 && ft_strcmp(dir->d_name, ".") != 0
			&& ft_strcmp(dir->d_name, "..") != 0)
		{
			if (dir->d_name[0] == '.' && !(flags & FLAG_A))
				continue ;
			print4("\n", "", "", "");
			tmp2 = ft_strjoin(fn, "/");
			tmp = ft_strjoin(tmp2, dir->d_name);
			ft_ls(tmp, flags);
			if (*tmp)
				free(tmp);
			if (*tmp2)
				free(tmp2);
		}
	closedir(dirp);
	return (0);
}

int				ft_ls(char const *fn, int flags)
{
	static int	i;
	static int	file_c;
	int			file_stat;

	file_stat = check_print_file(fn, flags);
	if (file_stat == 0)
	{
		print_dir(fn, flags, i, &file_c);
		i++;
	}
	else
		file_c++;
	if (flags & FLAG_R && file_stat == 0)
		recurse_ls(fn, flags);
	return (0);
}
