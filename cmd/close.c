/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcakmak <hcakmak@student.42istanbul.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:36:28 by hcakmak           #+#    #+#             */
/*   Updated: 2023/05/22 14:36:30 by hcakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_heredoc_fd(t_process *process)
{
	if (contain_heredoc(process) && process->heredoc_fd[0] > 2)
		close(process->heredoc_fd[0]);
}

void	close_all_fd(void)
{
	t_process	*process;

	process = g_ms.process;
	while (process)
	{
		close_heredoc_fd(process);
		if (process->fd[0] > 2)
			close(process->fd[0]);
		if (process->fd[1] > 2)
			close(process->fd[1]);
		process = process->next;
	}
}
