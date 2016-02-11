/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:54:21 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/11 10:50:32 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_error_malloc(void)
{
	ft_putstr_fd("minishell: Out of memory", 2);
	return (EXIT_FAILURE);
}

int					ft_error_execv(t_info *info)
{
	(void)info;
	ft_putstr_fd("minishell: Execv error", 2);
	return (EXIT_FAILURE);
}

int					ft_error_fork(t_info *info)
{
	(void)info;
	ft_putstr_fd("minishell: Fork error", 2);
	return (EXIT_FAILURE);
}

int					ft_error_chdir(char *illdir)
{
	struct stat		statfile;

	ft_putstr_fd("sh_cd: ", 2);
	if (stat(illdir, &statfile) == -1)
		ft_putstr_fd("no such file or directory: ", 2);
	else if (!(S_ISDIR(statfile.st_mode)))
		ft_putstr_fd("not a directory: ", 2);
	else if (!(statfile.st_mode & (S_IXUSR)))
		ft_putstr_fd("permission denied: ", 2);
	ft_putstr_fd(illdir, 2);
	return (EXIT_FAILURE);
}
