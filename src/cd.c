/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:01:50 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:01:51 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mini_cd(char *tmp)
{
	char	*sub;
	int		len;

	len = ft_strlen(tmp);
	sub = ft_substr(tmp, 3, len - 3);
	if (sub[0] == '\0' || sub[0] == '~')
	{
		sub = ft_strdup(getenv("HOME"));
	}
	g_return = chdir(sub);
	free(sub);
	if (g_return < 0)
		ft_putstrendl_fd("cd: no such file or directory", 1);
}
