/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:37:22 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:37:22 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew(char *str)
{
	t_list	*root;

	root = (t_list *)malloc(sizeof(*root));
	if (root == NULL)
		return (NULL);
	root -> data = str;
	root -> next = NULL;
	return (root);
}
