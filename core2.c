/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:28:14 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/21 12:11:17 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				path_len(char **path, int x)
{
	int			i;
	int			j;
	struct stat st;

	i = 0;
	j = 0;
	while (path[i])
	{
		lstat(path[i], &st);
		if ((S_ISDIR(st.st_mode) && x == 0)
		|| (!S_ISDIR(st.st_mode) && x == 1))
			j++;
		i++;
	}
	return (j);
}

char			*real_name(char *path, char *name)
{
	char *tmp_name;

	tmp_name = NULL;
	if (path && name)
	{
		tmp_name = ft_strjoin(path, "/");
		tmp_name = ft_strjoin(tmp_name, name);
	}
	return (tmp_name);
}

t_data_base		**data_base_size_init(int nb_file)
{
	int			i;
	t_data_base	**data;

	i = 0;
	if (nb_file < 0)
		return (NULL);
	data = (t_data_base**)malloc(sizeof(t_data_base*) * nb_file + 1);
	while (data && i < nb_file)
	{
		data[i] = (t_data_base*)malloc(sizeof(t_data_base));
		i++;
	}
	data[i] = NULL;
	return (data);
}

t_data_base		**stock_file(char *path, int nb_file, t_options *opt)
{
	int				i;
	DIR				*dir;
	struct dirent	*dir_src;
	t_data_base		**data;

	i = 0;
	if (!(dir = opendir(path)))
		return (NULL);
	data = data_base_size_init(nb_file);
	while ((dir_src = readdir(dir)) != NULL && i < nb_file)
	{
		if (dir_src->d_name[0] != '.' || opt->a == 1)
		{
			data[i]->name = ft_strdup(dir_src->d_name);
			data[i]->path = ft_strdup(real_name(path, dir_src->d_name));
			data[i]->type = dir_src->d_type;
			lstat(data[i]->path, &data[i]->st);
			i++;
		}
	}
	closedir(dir);
	return (data);
}

int				file_counter(char *path, t_options *opt)
{
	int				nbr_file;
	int				nbr_point;
	DIR				*dir;
	struct dirent	*env;

	nbr_file = 0;
	nbr_point = 0;
	if (!(dir = opendir(path)))
	{
		ft_putstr(path);
		ft_putstr(":\n");
		error_access(path);
		return (-1);
	}
	while ((env = readdir(dir)) != NULL)
	{
		if (env->d_name[0] == '.')
			nbr_point++;
		if (env->d_name[0] != '.')
			nbr_file++;
	}
	closedir(dir);
	return (opt->a == 1) ? nbr_file + nbr_point : nbr_file;
}
