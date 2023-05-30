/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:03:54 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:03:55 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_dir(char *tmp)
{
	tmp = getcwd(NULL, 0);
	if (tmp)
	{
		printf("%s\n", tmp);
		free(tmp);
		g_return = 0;
	}
	else
	{
		ft_putstrendl_fd("Error Occured!", 1);
		g_return = 127;
	}
}
