/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:49:37 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/04/24 13:27:28 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <errno.h>
# include "libft/libft.h"

# define BGREY "\033[1m\033[30m"
# define BRED "\033[1m\033[31m"
# define BGREEN "\033[1m\033[32"
# define BYELLOW "\033[1m\033[33m"
# define BBLUE "\033[1m\033[34m"
# define BPURPLE "\033[1m\033[35m"
# define BCYAN "\033[1m\033[36m"
# define BWHITE "\033[1m\033[37m"
# define RESET "\033[0m"
# define GREY "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

typedef struct		s_index
{
	int			i;
	int			j;
	int			k;
	int			l;
	int			n;
}					t_index;

typedef struct		s_options
{
	int				rec;
	int				a;
	int				l;
	int				r;
	int				t;
	int				x;
	int				max_pname;
	int				max_gname;
	int				max_nlink;
	int				max_ssize;
	int				max_pname_tmp;
	int				max_gname_tmp;
	int				max_nlink_tmp;
	int				max_ssize_tmp;
	int				total_blocks;
}					t_options;

typedef struct		s_data_base
{
	char			*name;
	char			*path;
	int				type;
	struct stat		st;
}					t_data_base;

void				parse_options(char **argv, t_options *opt);
void				error_usage(char argv);
char				**parse_paths(int argc, char **argv, t_options opt);
int					counter_paths(char **argv);
char				**stock_paths(int argc, char **argv, t_options opt);
char				**sort_ascii(char **path);
char				**rsort_ascii(char **path);
t_data_base			**data_base_size_init(int nb_file);
void				print_opt(t_options *opt, char *path, t_index index);
int					file_counter(char *path, t_options *opt);
t_data_base			**stock_file(char *path, int nb_file, t_options *opt);
char				*real_name(char *path, char *name);
void				test(t_options *opt, char **path, int j);
void				print_file(t_options *opt, char *path);
void				parse_info(t_data_base **data, t_options *opt);
int					intlen(int nbr);
void				ft_putstr_l(char *src, int len_max);
void				ft_putnbr_l(int src, int len_max);
void				print_rights(t_data_base *data, t_options *opt);
void				rights(struct stat st);
void				data_color(t_data_base *data);
void				putstr_color(char *cs, char *str, char *ce);
void				print_ls(t_data_base **data);
void				struct_swap(t_data_base **a, t_data_base **b);
t_data_base			**classic_sort(t_data_base **data);
t_data_base			**rev_classic_sort(t_data_base **data);
t_data_base			**time_sort(t_data_base **data);
t_data_base			**rev_time_sort(t_data_base **data);
t_data_base			**data_base_sort(t_data_base **data, t_options *opt);
void				print_ls_l(char *path, t_data_base **data, t_options *opt,
		int x);
void				recursion(char *path, t_options *opt, int x);
char				**check_path(int argc, char **path);
int					correct_path(char *path);
void				error_path(char *path);
char				isuid(struct stat st);
char				isgid(struct stat st);
char				isvtx(struct stat st);
void				info(t_data_base *data, struct stat st, t_options *opt,
					char *mtime);
void				error_access(char *path);
int					path_len(char **path, int x);
int					tab_len(t_data_base **data);
void				print_sym(t_data_base *data);
void				swap_path(char **a, char **b);
char				**time_sort_path(char **path);
char				**rev_time_sort_path(char **path);
char				**sort_path(char **path, t_options opt);

#endif
