/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 20:56:59 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/30 17:46:41 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <pwd.h>
# include <grp.h>
# include "libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>

# define FLAG_l			(1 << 0)
# define FLAG_R			(1 << 1)
# define FLAG_a			(1 << 2)
# define FLAG_r			(1 << 3)
# define FLAG_t			(1 << 4)

# define FLAG_mult		(1 << 12)

# define FT_LS			"./ft_ls: "
# define ILLOPT			"illegal option -- "
# define USAGE			"usage: ./ft_ls [-lRart] [file ...]"
# define NOFILE			"No such file or directory"

# define HALF_YEAR		15768000

typedef struct dirent	t_dir;
typedef struct stat		t_stat;
typedef struct winsize	t_win;

typedef struct			s_finfo
{
	char				*name;
	char				*path;
	t_stat				*stat;
	t_dir				*dir;
}						t_finf;

int						ft_ls(char const *fn, int flags);
int						read_dirs(void);
t_finf					*init_finf(const char *path, const t_dir *dir, const int flags);
void					lst_insert_new(char const *fn, int const flags, const t_dir *dir, t_list **root);

void					print4(char const *s1, char const *s2,
							char const *s3, char const *s4);

char	*get_data(t_finf const *f);
int		print_data(t_finf const *f);

char	*get_group_name(t_finf const *f);
int		print_group_name(t_finf const *f);

int	get_links_count(t_finf const *f);
int	print_links_count(t_finf const *f);

char	*get_name(t_finf const *f);
int	print_name(t_finf const *f);

char	*get_owner_name(t_finf const *f);
int		print_owner_name(t_finf const *f);

int	get_permission(t_finf const *f);
int	print_permission(t_finf const *f);

int	get_size(t_finf const *f);
int	print_size(t_finf const *f);

int		get_type(t_finf const *f);
int		print_type(t_finf const *f);

int	print_table(t_finf const *f);
int	print_simple(t_finf const *f);

void	set_colors(char const *fg, char const *bg);

#endif
