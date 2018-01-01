/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:00:07 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/21 14:55:20 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_access(char *path)
{
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": Permission denied\n");
}

void	print_ls(t_data_base **data)
{
	int i;

	i = 0;
	while (data && data[i])
	{
		if (data[i])
		{
			data_color(data[i]);
			i++;
		}
		ft_putchar('\n');
	}
}

void	print_ls_l(char *path, t_data_base **data, t_options *opt, int x)
{
	int i;

	parse_info(data, opt);
	if (x == 1 && file_counter(path, opt) > 0)
	{
		ft_putstr("total ");
		ft_putnbr(opt->total_blocks);
		ft_putchar('\n');
	}
	i = 0;
	while (data && data[i])
	{
		print_rights(data[i], opt);
		i++;
	}
	ft_memset(&opt->max_pname, 0, sizeof(int) * 9);
}

void	putstr_color(char *cs, char *str, char *ce)
{
	if (cs[0] == '/' && cs[1] == '/')
		ft_putstr(cs + 1);
	else
		ft_putstr(cs);
	ft_putstr(str);
	ft_putstr(ce);
}

void	data_color(t_data_base *data)
{
	if (data->type == DT_BLK)
		putstr_color(WHITE, data->name, RESET);
	else if (data->type == DT_CHR)
		putstr_color(YELLOW, data->name, RESET);
	else if (data->type == DT_DIR)
		putstr_color(BCYAN, data->name, RESET);
	else if (data->type == DT_FIFO)
		putstr_color(GREEN, data->name, RESET);
	else if (data->type == DT_LNK)
		putstr_color(PURPLE, data->name, RESET);
	else if (data->st.st_mode == 33261)
		putstr_color(RED, data->name, RESET);
	else if (data->type == DT_SOCK)
		putstr_color(RED, data->name, RESET);
	else if (data->type == DT_UNKNOWN)
		putstr_color(WHITE, data->name, RESET);
	else
		ft_putstr(data->name);
}
