/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:06:53 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/24 13:07:12 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**sort_path(char **path, t_options opt)
{
	if (opt.r == 0 && opt.t == 0)
		path = sort_ascii(path);
	else if (opt.r == 1 && opt.t == 0)
		path = rsort_ascii(path);
	else if (opt.r == 0 && opt.t == 1)
		path = time_sort_path(path);
	else if (opt.r == 1 & opt.t == 1)
		path = rev_time_sort_path(path);
	return (path);
}

char	**time_sort_path(char **path)
{
	int			i;
	struct stat st;
	struct stat st_cmp;

	i = 0;
	while (path[i + 1])
	{
		lstat(path[i], &st);
		lstat(path[i + 1], &st_cmp);
		if (st.st_mtime == st_cmp.st_mtime &&
				(ft_strcmp(path[i], path[i + 1]) > 0))
		{
			swap_path(&path[i], &path[i + 1]);
			i = -1;
		}
		else if (st.st_mtime < st_cmp.st_mtime)
		{
			swap_path(&path[i], &path[i + 1]);
			i = -1;
		}
		i++;
	}
	return (path);
}

char	**rev_time_sort_path(char **path)
{
	int			i;
	struct stat st;
	struct stat st_cmp;

	i = 0;
	while (path[i + 1])
	{
		lstat(path[i], &st);
		lstat(path[i + 1], &st_cmp);
		if (st.st_mtime == st_cmp.st_mtime &&
				(ft_strcmp(path[i], path[i + 1]) < 0))
		{
			swap_path(&path[i], &path[i + 1]);
			i = -1;
		}
		else if (st.st_mtime > st_cmp.st_mtime)
		{
			swap_path(&path[i], &path[i + 1]);
			i = -1;
		}
		i++;
	}
	return (path);
}
