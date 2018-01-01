/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:34:41 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/19 12:34:46 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse_info(t_data_base **data, t_options *opt)
{
	int				i;
	struct passwd	*pwd;
	struct group	*grp;

	i = 0;
	while (data && data[i] != NULL)
	{
		pwd = getpwuid(data[i]->st.st_uid);
		grp = getgrgid(data[i]->st.st_gid);
		opt->total_blocks += data[i]->st.st_blocks;
		opt->max_pname_tmp = (int)ft_strlen(pwd->pw_name);
		opt->max_gname_tmp = (int)ft_strlen(grp->gr_name);
		opt->max_nlink_tmp = intlen(data[i]->st.st_nlink);
		opt->max_ssize_tmp = intlen(data[i]->st.st_size);
		if (opt->max_pname < opt->max_pname_tmp)
			opt->max_pname = opt->max_pname_tmp;
		if (opt->max_gname < opt->max_gname_tmp)
			opt->max_gname = opt->max_gname_tmp;
		if (opt->max_nlink < opt->max_nlink_tmp)
			opt->max_nlink = opt->max_nlink_tmp;
		if (opt->max_ssize < opt->max_ssize_tmp)
			opt->max_ssize = opt->max_ssize_tmp;
		i++;
	}
}

char	isuid(struct stat st)
{
	(S_IRUSR & st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWUSR & st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	if (S_ISUID & st.st_mode)
	{
		if (S_IXUSR & st.st_mode)
			return ('s');
		else
			return ('S');
	}
	else
	{
		if (S_IXUSR & st.st_mode)
			return ('x');
		else
			return ('-');
	}
}

char	isgid(struct stat st)
{
	(S_IRGRP & st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWGRP & st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	if (S_ISGID & st.st_mode)
	{
		if (S_IXGRP & st.st_mode)
			return ('s');
		else
			return ('S');
	}
	else
	{
		if (S_IXGRP & st.st_mode)
			return ('x');
		else
			return ('-');
	}
}

char	isvtx(struct stat st)
{
	(S_IROTH & st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWOTH & st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	if (S_ISVTX & st.st_mode)
	{
		if (S_IXOTH & st.st_mode)
			return ('t');
		else
			return ('T');
	}
	else
	{
		if (S_IXOTH & st.st_mode)
			return ('x');
		else
			return ('-');
	}
}
