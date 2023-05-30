/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in_handle2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkilic <hkilic@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:08:16 by hkilic            #+#    #+#             */
/*   Updated: 2023/02/16 22:09:56 by hkilic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redir2_in_handle(char **str, int i, t_envp *s_envp)
{
	int		fd;
	char	*eof;
	char	*temp;

	temp = sub_redir(str, i);
	if (str[i + 2] && str[i + 2][0] == '>')
	{
		eof = ft_strdup(str[i + 1]);
		here_doc2("b.txt", eof);
		fd = open("b.txt", O_RDONLY, 0777);
		mixed_redir(str[i + 3], temp, fd, s_envp);
	}	
	else
	{
		eof = ft_strdup(str[i + 1]);
		here_doc(TMP_FILE, eof);
		fd = open(TMP_FILE, O_RDONLY, 0777);
		execute_dir(temp, fd, 0, s_envp);
	}
	if (eof[0] != '\0')
		free(eof);
	if (temp[0] != '\0')
		free(temp);
}
