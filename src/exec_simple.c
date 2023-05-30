/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:02:51 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 23:52:37 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_child(char **parse, t_envp *s_envp)
{
	char	*dollar;
	char	*path;

	if (parse[1] && parse[1][0] == '$')
	{
		dollar = getenv(ft_strtrim(parse[1], "$"));
		free(parse[1]);
		parse[1] = ft_strdup(dollar);
	}
	path = find_path_simple(parse[0]);
	if (execve(path, parse, s_envp->envp) != 0)
	{
		g_return = 127;
		ft_putstr_fd("command not found\n", 1);
		exit(g_return);
	}
	kill(getpid(), SIGTERM);
}

void	execsimple(char *str, t_envp *s_envp)
{
	pid_t	pid;
	char	**commands;

	commands = ft_split(str, ' ');
	pid = fork();
	if (pid < 0)
	{
		g_return = 127;
		ft_putstr_fd("Failed forking child", 1);
	}
	else if (pid == 0)
		exec_child(commands, s_envp);
	waitpid(pid, &g_return, 0);
	if (WIFEXITED(g_return))
		g_return = WEXITSTATUS(g_return);
	else
		g_return = 0;
	ft_free_str(commands);
}
