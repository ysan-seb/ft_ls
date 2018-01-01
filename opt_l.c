/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:28:35 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/21 12:10:50 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_sym(t_data_base *data)
{
	int ret;

	ret = 0;
	data_color(data);
	ft_putstr(" -> ");
	ret = readlink(data->path, data->path, 512);
	data->path[ret] = '\0';
	ft_putstr(data->path);
}

void	print_rights(t_data_base *data, t_options *opt)
{
	char			*mtime;
	struct stat		st;
	char			*tmp_a;
	char			*tmp_b;

	lstat(data->path, &st);
	mtime = ctime(&data->st.st_mtime);
	if (data->st.st_mtime > 3689712000)
		mtime = "Jan  1  10000";
	else if (data->st.st_mtime > 51119144000)
	{
		tmp_a = ft_strsub(mtime, 4, 6);
		tmp_b = ft_strsub(mtime, 19, 5);
		mtime = ft_strjoin(tmp_a, tmp_b);
	}
	else
		mtime = ft_strsub(mtime, 4, 12);
	rights(st);
	info(data, st, opt, mtime);
	if (S_ISLNK(st.st_mode))
		print_sym(data);
	else
		data_color(data);
	ft_putchar('\n');
}

void	info(t_data_base *data, struct stat st, t_options *opt, char *mtime)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(st.st_uid);
	grp = getgrgid(st.st_gid);
	ft_putstr("  ");
	ft_putnbr_l(st.st_nlink, opt->max_nlink);
	ft_putchar(' ');
	ft_putstr_l(pwd->pw_name, opt->max_pname);
	ft_putstr("  ");
	ft_putstr_l(grp->gr_name, opt->max_gname);
	ft_putstr("  ");
	if ((S_ISBLK(st.st_mode)) || (S_ISCHR(st.st_mode)))
	{
		ft_putnbr_l(major(st.st_rdev), 3);
		ft_putstr(", ");
		ft_putnbr_l(minor(st.st_rdev), 3);
	}
	else
		ft_putnbr_l(data->st.st_size, opt->max_ssize);
	ft_putchar(' ');
	ft_putstr(mtime);
	ft_putchar(' ');
}

void	rights(struct stat st)
{
	if (S_ISREG(st.st_mode))
		ft_putchar('-');
	else if (S_ISDIR(st.st_mode))
		ft_putchar('d');
	else if (S_ISCHR(st.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(st.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(st.st_mode))
		ft_putchar('p');
	else if (S_ISLNK(st.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(st.st_mode))
		ft_putchar('s');
	ft_putchar(isuid(st));
	ft_putchar(isgid(st));
	ft_putchar(isvtx(st));
}
