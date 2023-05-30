/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:03:19 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:49:23 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_shell(void)
{
	printf(
		"███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     \n"
		"████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     \n"
		"██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     \n"
		"██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     \n"
		"██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n"
		"╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n"
		"                                  developed by hkilic & ikayaalp");
	printf("\n\n\nUSER is: @%s\n", getenv("USER"));
	fflush(stdout);
}

t_envp	*init_envp(char **envp)
{
	int		i;
	t_envp	*s_env;

	i = 0;
	s_env = malloc(sizeof(t_envp));
	s_env->env_len = env_len(envp);
	s_env->envp = (char **)malloc(sizeof(char *) * (s_env->env_len * 2));
	if (!s_env->envp)
	{
		ft_putstr_fd("Malloc Failed!", 1);
		g_return = 127;
	}
	while (envp[i])
	{
		s_env->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	s_env->envp[i] = NULL;
	return (s_env);
}

t_envp	*init(char **envp)
{
	t_envp	*s_envp;

	init_shell();
	g_return = 0;
	s_envp = init_envp(envp);
	return (s_envp);
}
