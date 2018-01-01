/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:05:14 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/19 12:24:09 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse_options(char **argv, t_options *options)
{
	int i;
	int j;

	i = 1;
	while (argv[i] && !ft_strequ(argv[i], "--"))
	{
		j = 1;
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			error_usage('-');
		while (argv[i][j] && argv[i][0] == '-' && argv[i][1])
		{
			if (argv[i][j] != 'R' && argv[i][j] != 'a' && argv[i][j] != 'l'
					&& argv[i][j] != 'r' && argv[i][j] != 't')
				error_usage(argv[i][j]);
			options->rec = (argv[i][j] == 'R') ? 1 : options->rec;
			options->a = (argv[i][j] == 'a') ? 1 : options->a;
			options->l = (argv[i][j] == 'l') ? 1 : options->l;
			options->r = (argv[i][j] == 'r') ? 1 : options->r;
			options->t = (argv[i][j] == 't') ? 1 : options->t;
			j++;
		}
		i++;
	}
}

void	error_usage(char argv)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(argv);
	ft_putstr("\nusage: ft_ls [-Raltr] [file ...]\n");
	exit(EXIT_FAILURE);
}
