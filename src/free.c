/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:03:14 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:03:14 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_lstdelone(t_list *lst)
{
	free(lst->data);
	free(lst);
	lst = NULL;
}

void	ft_free_list(t_list **list)
{
	t_list	*tmp;

	if (list)
	{
		while (*list)
		{
			tmp = (*list)->next;
			ft_lstdelone(*list);
			*list = tmp;
		}
		free(list);
	}
}

void	ft_free_env(t_envp *s_envp)
{
	int	i;

	i = 0;
	while (s_envp->envp[i])
	{
		free(s_envp->envp[i]);
		i++;
	}
	free(s_envp);
	s_envp = NULL;
}
