# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 07:19:36 by ysan-seb          #+#    #+#              #
#    Updated: 2017/04/24 13:11:06 by ysan-seb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ls

SRCS	=	main.c check_options.c check_paths.c check_paths2.c core.c core2.c \
			opt_l.c opt_l2.c tools.c opt_art.c print_opt.c opt_rec.c \
			sort_path.c tools2.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	= -Wall -Werror -Wextra 

HEADER = -I./

LIBFT = ./libft/libft.a

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		@make -C libft/
		@$(CC) -o $(NAME) $(OBJS) $(HEADER) $(LIBFT)

clean	:
		@make -C libft/ clean
		@$(RM) $(OBJS)

fclean:
		@make -C libft/ fclean
		@$(RM) $(NAME) $(OBJS)

re	:	fclean all
