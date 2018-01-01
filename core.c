/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:14:04 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/21 14:49:18 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			index_init(t_index *index, char **path)
{
	index->i = 0;
	index->j = path_len(path, 1);
	index->k = path_len(path, 0);
	index->n = (index->j > 0 && index->k > 0) ? 1 : index->n;
	index->l = (index->k > 1) ? 1 : 0;
}

void			test(t_options *opt, char **path, int x)
{
	t_index		index;
	struct stat st;

	index_init(&index, path);
	while (path[index.i])
	{
		lstat(path[index.i], &st);
		if (S_ISDIR(st.st_mode) && x == 1)
		{
			print_opt(opt, path[index.i], index);
			index.k--;
		}
		else if (!S_ISDIR(st.st_mode) && x == 0)
		{
			print_file(opt, path[index.i]);
			index.j--;
			if (index.j == 0 && index.k > 0)
				ft_putchar('\n');
		}
		index.i++;
		if (path[index.i] == NULL && x == 0)
			test(opt, path, 1);
	}
}

void			print_file(t_options *opt, char *path)
{
	t_data_base **data;

	if (opt->rec == 0 && opt->l == 0)
	{
		ft_putstr(path);
		ft_putchar('\n');
	}
	else if (opt->rec == 0 && opt->l == 1)
	{
		data = data_base_size_init(10);
		data[0]->name = ft_strdup(path);
		data[0]->path = ft_strdup(path);
		data[1] = NULL;
		lstat(data[0]->path, &data[0]->st);
		print_ls_l(path, data, opt, 0);
	}
	else if (opt->rec == 1)
	{
		ft_putstr(path);
		ft_putchar('\n');
	}
}

void			print_opt(t_options *opt, char *path, t_index index)
{
	int			nb_file;
	t_data_base	**data;

	nb_file = file_counter(path, opt);
	if (nb_file == -1)
		return ;
	data = stock_file(path, nb_file, opt);
	data = data_base_sort(data, opt);
	if ((index.l == 1 && opt->rec == 0) || (index.n == 1 && opt->rec == 0))
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (opt->rec == 0 && opt->l == 0)
		print_ls(data);
	else if (opt->rec == 0 && opt->l == 1)
		print_ls_l(path, data, opt, 1);
	else if (opt->rec == 1)
		recursion(path, opt, index.k);
	if (index.k > 1)
		ft_putchar('\n');
}
