/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcakmak <hcakmak@student.42istanbul.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:35:42 by hcakmak           #+#    #+#             */
/*   Updated: 2023/05/22 14:35:43 by hcakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(void)
{
	char	*result;

	result = getcwd((void *)0, 0);
	if (!result)
		perror("minishell ");
	else
		printf("%s\n", result);
	free(result);
	if (!is_parent())
		exit(errno);
}
