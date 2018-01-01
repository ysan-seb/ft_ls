/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:06:35 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/21 12:48:41 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**parse_paths(int argc, char **argv, t_options opt)
{
	int		nb_path;
	char	**path;

	nb_path = counter_paths(argv);
	if (nb_path < 1)
	{
		path = (char **)malloc(sizeof(char *) * 2);
		path[0] = ft_strdup(".");
		path[1] = NULL;
		return (path);
	}
	else
		path = stock_paths(argc, argv, opt);
	return (path);
}

int		counter_paths(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (argv[i] != NULL && argv[i][0] == '-')
		i++;
	while (argv[i] != NULL && argv[i][0] != '-')
	{
		i++;
		j++;
	}
	return (j);
}

char	**stock_paths(int argc, char **argv, t_options opt)
{
	int		i;
	int		j;
	char	**path;

	i = 1;
	j = 0;
	path = (char **)malloc(sizeof(char*) * argc);
	while (argv[i] != NULL && argv[i][0] == '-')
		i++;
	while (argv[i] != NULL)
	{
		path[j] = ft_strdup(argv[i]);
		i++;
		j++;
	}
	path[j] = NULL;
	path = sort_path(path, opt);
	return (path);
}

char	**check_path(int argc, char **path)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = (char **)malloc(sizeof(char *) * (argc + 1));
	while (path[i] != NULL)
	{
		if ((correct_path(path[i])) == 0)
		{
			tmp[j] = ft_strdup(path[i]);
			j++;
		}
		i++;
	}
	tmp[j] = NULL;
	free(path);
	return (tmp);
}
