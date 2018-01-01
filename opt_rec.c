/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:21:51 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/24 13:05:55 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursion(char *path, t_options *opt, int x)
{
	static int		i;
	DIR				*dir;
	struct dirent	*tmp;
	char			*tmp_path;
	t_data_base		**data;

	if (!(data = stock_file(path, file_counter(path, opt), opt)))
		return ;
	data = data_base_sort(data, opt);
	if ((dir = opendir(path)))
		putstr_color(path, ":\n", NULL);
	(opt->l == 0) ? print_ls(data) : print_ls_l(path, data, opt, 1);
	while ((tmp = readdir(dir)) != NULL)
	{
		if (tmp->d_type == 4 && i > 1 && tmp->d_name[0] != '.')
		{
			tmp_path = ft_strjoin(path, "/");
			tmp_path = ft_strjoin(tmp_path, tmp->d_name);
			ft_putchar('\n');
			recursion(tmp_path, opt, x);
		}
		i++;
	}
	closedir(dir);
}
