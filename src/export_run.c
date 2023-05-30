/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:02:56 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:02:56 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_run_exist(char *var_name, char *var_val, t_envp *s_envp, int i)
{
	char	*tmp;

	if (s_envp->envp[i][0] != '\0')
		free(s_envp->envp[i]);
	s_envp->envp[i] = NULL;
	if (var_val)
	{
		tmp = ft_strjoin("=", var_val);
		s_envp->envp[i] = ft_strjoin(var_name, tmp);
		free(tmp);
	}
	else
		s_envp->envp[i] = ft_strjoin(var_name, " ");
}

void	export_run_nonexistent(char *var_name, char *var_val,
	t_envp *s_envp, int i)
{
	char	*dollar;
	char	*tmp;
	char	*tmp2;

	s_envp->env_len++;
	realloc_envp(s_envp);
	if (var_val)
	{
		if (count(var_val, '$'))
		{
			tmp2 = ft_strtrim(var_val, "$");
			dollar = ft_strdup(getenv(tmp2));
			free(tmp2);
			ft_strcpy(var_val, dollar);
			free(dollar);
		}
		tmp = ft_strjoin("=", var_val);
		s_envp->envp[i] = ft_strjoin(var_name, tmp);
		free(tmp);
	}
	else if (!var_val)
		s_envp->envp[i] = ft_strjoin(var_name, " ");
}
