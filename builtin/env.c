/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:33:40 by hcakmak           #+#    #+#             */
/*   Updated: 2023/05/25 23:00:12 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	compare(const char *a, const char *b)
{
	while (*a && (*a == *b))
	{
		a++;
		b++;
	}
	return (*(unsigned char *)a - *(unsigned char *)b);
}

char	**sort_env(char **env)
{
	int		i;
	int		j;
	char	**sorted_env;
	char	*temp;

	sorted_env = (char **)malloc((env_len() + 1) * sizeof(char *));
	i = -1;
	while (++i < env_len())
		sorted_env[i] = ft_strdup(env[i]);
	i = -1;
	while (++i < env_len() - 1)
	{
		j = -1;
		while (++j < env_len() - i - 1)
		{
			if (compare(sorted_env[j], sorted_env[j + 1]) > 0)
			{
				temp = sorted_env[j];
				sorted_env[j] = sorted_env[j + 1];
				sorted_env[j + 1] = temp;
			}
		}
	}
	sorted_env[env_len()] = NULL;
	return (sorted_env);
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

static	void	write_export(void)
{
	int		i;
	int		j;
	char	**env;

	env = sort_env(g_ms.env);
	i = 0;
	while (env[i])
	{
		j = 0;
		printf("declare -x ");
		while (env[i][j])
		{
			printf("%c", env[i][j]);
			if (env[i][j] == '=')
				printf("\"");
			j++;
		}
		printf("\"\n");
		i++;
	}
	free_env(env);
}

void	builtin_env(const char *str)
{
	char	**env;

	env = g_ms.env;
	if (!ft_strncmp(str, "export", ft_strlen(str)))
		write_export();
	else
	{
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	if (!is_parent())
		exit (EXIT_SUCCESS);
}
