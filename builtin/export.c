/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:34:06 by hcakmak           #+#    #+#             */
/*   Updated: 2023/05/25 17:22:52 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_env(char *str)
{
	char	*head;

	head = ft_strchr(str, '=');
	if (!head)
		return (FALSE);
	if (head == str)
		return (FALSE);
	while (*str)
	{
		if (is_whitespace(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

void	add_env(char *str)
{
	int		i;
	char	**env;
	char	**new_env;

	i = 0;
	env = g_ms.env;
	new_env = ft_calloc(sizeof(char **), env_len() + 2);
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(str);
	free_array(g_ms.env);
	g_ms.env = new_env;
}

int	is_include(char *str)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	env = g_ms.env;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && str[j])
		{
			if (str[j] == '=' && env[i][j] == '=')
				return (i);
			if (str[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (-1);
}

void	add_new_env(char **input)
{
	int		pos;
	char	*tmp;

	while (*input)
	{
		if (check_env(*input))
		{
			pos = is_include(*input);
			if (pos != -1)
			{
				tmp = g_ms.env[pos];
				g_ms.env[pos] = ft_strdup(*input);
				free(tmp);
			}
			else
				add_env(*input);
		}
		input++;
	}
}

void	builtin_export(char **input)
{
	if (!*(++input))
		builtin_env("export");
	else
		add_new_env(input);
	set_paths();
	if (!is_parent())
		exit (EXIT_SUCCESS);
}
