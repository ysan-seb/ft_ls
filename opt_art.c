/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_art.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:15:45 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/19 12:33:31 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data_base		**data_base_sort(t_data_base **data, t_options *opt)
{
	if (tab_len(data) > 1)
	{
		if (opt->a == 0 && opt->r == 0 && opt->t == 0)
			data = classic_sort(data);
		else if (opt->a == 1 && opt->r == 0 && opt->t == 0)
			data = classic_sort(data);
		else if (opt->a == 0 && opt->r == 1 && opt->t == 0)
			data = rev_classic_sort(data);
		else if (opt->a == 0 && opt->r == 0 && opt->t == 1)
			data = time_sort(data);
		else if (opt->a == 1 && opt->r == 1 && opt->t == 0)
			data = rev_classic_sort(data);
		else if (opt->a == 1 && opt->r == 0 && opt->t == 1)
			data = time_sort(data);
		else if (opt->a == 0 && opt->r == 1 && opt->t == 1)
			data = rev_time_sort(data);
		else if (opt->a == 1 && opt->r == 1 && opt->t == 1)
			data = rev_time_sort(data);
	}
	return (data);
}

t_data_base		**classic_sort(t_data_base **data)
{
	int i;

	i = 0;
	while (data && data[i + 1])
	{
		if (ft_strcmp(data[i]->name, data[i + 1]->name) > 0)
		{
			struct_swap(&data[i], &data[i + 1]);
			i = -1;
		}
		i++;
	}
	return (data);
}

t_data_base		**rev_classic_sort(t_data_base **data)
{
	int i;

	i = 0;
	while (data && data[i + 1])
	{
		if (ft_strcmp(data[i]->name, data[i + 1]->name) < 0)
		{
			struct_swap(&data[i], &data[i + 1]);
			i = -1;
		}
		i++;
	}
	return (data);
}

t_data_base		**time_sort(t_data_base **data)
{
	int i;

	i = 0;
	while (data[i + 1])
	{
		if (data[i]->st.st_mtime == data[i + 1]->st.st_mtime &&
				(ft_strcmp(data[i]->name, data[i + 1]->name) > 0))
		{
			struct_swap(&data[i], &data[i + 1]);
			i = -1;
		}
		else if (data[i]->st.st_mtime < data[i + 1]->st.st_mtime)
		{
			struct_swap(&data[i], &data[i + 1]);
			i = -1;
		}
		i++;
	}
	return (data);
}

t_data_base		**rev_time_sort(t_data_base **data)
{
	int i;

	i = 0;
	while (data[i + 1])
	{
		if (data[i]->st.st_mtime == data[i + 1]->st.st_mtime
				&& (ft_strcmp(data[i]->name, data[i + 1]->name) < 0))
		{
			struct_swap(&data[i], &data[i + 1]);
			i = -1;
		}
		else if (data[i]->st.st_mtime > data[i + 1]->st.st_mtime)
		{
			struct_swap(&data[i], &data[i + 1]);
			i = -1;
		}
		i++;
	}
	return (data);
}
