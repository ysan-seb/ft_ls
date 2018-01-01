/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:36:48 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/24 13:08:48 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				tab_len(t_data_base **data)
{
	int i;

	i = 0;
	while (data && data[i])
		i++;
	return (i);
}

int				intlen(int nbr)
{
	int i;

	i = 1;
	while ((nbr = nbr / 10))
		i++;
	return (i);
}

void			ft_putstr_l(char *src, int len_max)
{
	int i;

	i = len_max - ft_strlen(src);
	ft_putstr(src);
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}

void			ft_putnbr_l(int src, int len_max)
{
	int i;

	i = len_max - intlen(src);
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(src);
}
