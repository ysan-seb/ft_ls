/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:07:47 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/24 13:10:48 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			struct_swap(t_data_base **a, t_data_base **b)
{
	t_data_base *c;

	c = *a;
	*a = *b;
	*b = c;
}

void			swap_path(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}
