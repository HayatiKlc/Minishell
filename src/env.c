/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:02:23 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:02:24 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i] != NULL)
		ft_putstrendl_fd(envp[i], 1);
	g_return = 0;
}
