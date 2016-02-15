/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:35:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 14:02:15 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_cd(t_info *info)
{
	char		*path;
	char		*oldpath;

	if (info->args[1] == NULL)
	{
		path = sh_get_in_env("HOME", info->env);
		chdir(path);
	}
	else if (ft_strequ(info->args[1], "-"))
	{
		path = sh_get_in_env("OLDPWD", info->env);
		chdir(path);
	}
	else
	{
		if (chdir(info->args[1]) != 0)
			ft_error_chdir(info->args[1]);
	}
	oldpath = ft_strjoin("OLDPWD=", info->path);
	sh_replace_env(oldpath, info->env);
	return (1);
}

int				sh_help(t_info *info)
{
	int			i;

	(void)info;
	ft_putendl("Gwoodwar Minishell");
	ft_putendl("Type program names and arguments, press enter.");
	ft_putendl("Here are the built in:");
	i = 0;
	while (i < sh_nb_builtin())
	{
		ft_printf("     %s,\n", g_builtin_str[i]);
		i++;
	}
	return (1);
}

int				sh_exit(t_info *info)
{
	(void)info;
	ft_putendl("exit");
	exit(EXIT_SUCCESS);
}

int				sh_pwd(t_info *info)
{
	char		buf[4096];

	(void)info;
	ft_bzero(buf, 4096);
	getcwd(buf, 4096);
	ft_putendl(buf);
	return (1);
}

int				sh_printenv(t_info *info)
{
	int			i;

	i = 0;
	while (info->env[i])
	{
		ft_putendl(info->env[i]);
		i++;
	}
	return (1);
}

int				sh_echo(t_info *info)
{
	int			i;

	if (ft_strequ(info->args[1], "-n"))
	{
		i = 2;
		while (info->args[i + 1])
		{
			ft_printf("%s ", info->args[i]);
			i++;
		}
		ft_printf("%s", info->args[i]);
	}
	else
	{
		i = 1;
		while (info->args[i + 1])
		{
			ft_printf("%s ", info->args[i]);
			i++;
		}
		ft_printf("%s\n", info->args[i]);
	}
	return (EXIT_SUCCESS);
}
