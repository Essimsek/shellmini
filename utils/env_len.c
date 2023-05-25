/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcakmak <hcakmak@student.42istanbul.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:35:43 by hcakmak           #+#    #+#             */
/*   Updated: 2023/05/25 15:35:44 by hcakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_len(void)
{
	char	**env;

	env = g_ms.env;
	while (*env)
		env++;
	return (env - g_ms.env);
}
