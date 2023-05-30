/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:02:35 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:02:35 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**sort_envp(char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	while (envp[i] && envp[i + 1])
	{
		if (ft_strcmp(envp[i], envp[i + 1]) > 0)
		{
			tmp = envp[i];
			envp[i] = envp[i + 1];
			envp[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (envp);
}

void	print_export(t_envp *s_envp)
{
	int		i;
	char	**str;
	char	*temp;

	i = 0;
	str = sort_envp(s_envp->envp);
	while (str[i])
	{
		temp = ft_strjoin("declare -x ", str[i]);
		ft_putstrendl_fd(temp, 1);
		free(temp);
		i++;
	}
}
