/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:21:37 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/19 12:32:57 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	struct_init(t_options *opt)
{
	opt->l = 0;
	opt->rec = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
	opt->max_pname = 0;
	opt->max_gname = 0;
	opt->max_nlink = 0;
	opt->max_ssize = 0;
	opt->total_blocks = 0;
}

int		main(int argc, char **argv)
{
	t_options	opt;
	char		**path;

	struct_init(&opt);
	parse_options(argv, &opt);
	path = parse_paths(argc, argv, opt);
	path = check_path(argc, path);
	test(&opt, path, 0);
	return (0);
}
