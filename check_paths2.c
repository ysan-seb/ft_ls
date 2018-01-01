/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:25:40 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/19 13:42:57 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**sort_ascii(char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i + 1] != NULL)
	{
		if (ft_strcmp(path[i], path[i + 1]) > 0)
		{
			tmp = path[i];
			path[i] = path[i + 1];
			path[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (path);
}

char	**rsort_ascii(char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i + 1] != NULL)
	{
		if (ft_strcmp(path[i], path[i + 1]) < 0)
		{
			tmp = path[i];
			path[i] = path[i + 1];
			path[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (path);
}

int		correct_path(char *path)
{
	DIR			*dir;
	struct stat st;
	int			errno;

	lstat(path, &st);
	if (!(dir = opendir(path)))
	{
		if (errno != ENOTDIR && errno != EACCES && !(S_ISLNK(st.st_mode)))
		{
			error_path(path);
			return (1);
		}
		else
		{
			return (0);
		}
	}
	closedir(dir);
	return (0);
}

void	error_path(char *path)
{
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": No such file or directory\n");
}
