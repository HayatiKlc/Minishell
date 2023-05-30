/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:04:24 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:06:50 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handler_child(int signum)
{
	if (signum == SIGINT)
	{
		g_return = 130;
		write(1, "\n", 1);
	}
	if (signum == SIGQUIT)
	{
		g_return = 131;
		write(1, "\n", 1);
		ft_putstrendl_fd("Quit Child\n", 1);
	}
}

static void	handler_main(int signum)
{
	g_return = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	(void)signum;
}

void	signals(int signum)
{
	if (signum == 1)
	{
		signal(SIGINT, handler_main);
		signal(SIGQUIT, SIG_IGN);
	}
	if (signum == 2)
	{
		signal(SIGINT, handler_child);
		signal(SIGQUIT, handler_child);
	}
}
