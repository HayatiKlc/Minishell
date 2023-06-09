/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:04:10 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:04:10 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirect_out(char **str, int i, t_envp *s_envp)
{
	if (str[i + 1] == NULL || str[i + 1][0] == '>' || str[i + 1][0] == '<'
		|| str[i + 1][0] == '\0')
		return (0);
	if (!ft_strcmp(str[i], ">>"))
	{
		redir2_out_handle(str, i, s_envp);
		return (0);
	}
	else if (!ft_strcmp(str[i], ">"))
	{
		redir_out_handle(str, i, s_envp);
		return (0);
	}
	return (1);
}

int	redirect_in(char **str, int i, t_envp *s_envp)
{
	if (str[i + 1] && !ft_strcmp(str[i], "<"))
	{
		redir_in_handle(str, i, s_envp);
		return (0);
	}
	else if (str[i + 1] && !ft_strcmp(str[i], "<<"))
	{
		redir2_in_handle(str, i, s_envp);
		return (0);
	}
	return (1);
}

void	check_dir(char *str, t_envp *s_envp)
{
	int		i;
	char	**commands;

	i = 0;
	commands = ft_split(str, ' ');
	while (commands[i])
	{
		if ((!ft_strcmp(commands[i], ">") || !ft_strcmp(commands[i], ">>")))
		{
			redirect_out(commands, i, s_envp);
			break ;
		}
		else if ((!ft_strcmp(commands[i], "<") || \
		!ft_strcmp(commands[i], "<<")))
		{
			redirect_in(commands, i, s_envp);
			break ;
		}	
		i++;
	}
	ft_free_str(commands);
}
