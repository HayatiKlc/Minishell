/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:03:37 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:03:38 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	**add_list(char **str, t_list **mini)
{
	int		i;
	char	*temp;
	t_list	*temp2;

	i = 0;
	while (str[i])
	{
		temp = ft_strtrim(str[i], " ");
		temp2 = ft_lstnew(temp);
		ft_lstadd_back(mini, temp2);
		temp = NULL;
		temp2 = NULL;
		i++;
	}
	free (temp);
	free (temp2);
	return (mini);
}
