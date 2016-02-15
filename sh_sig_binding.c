/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_sig_binding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:12:22 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/15 14:26:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static t_info	*g_info = NULL;

static void		sh_sig_bind(int sig)
{
	(void)sig;
	ft_printf("\n\033[31m%s\033[39m $> ", g_info->cursdir);
	SET(g_info->sig, SIG_C);
}

void			sh_sig_init(t_info *info)
{
	(void)info;
	g_info = info;
	signal(SIGINT, &sh_sig_bind);
}
