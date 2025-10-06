/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:58:16 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/06 11:11:36 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

char	*try_path(char *cmd, char *path)
{
	char	*new_path;
	char	*new_cmd;

	if (!path || !cmd)
		return (NULL);
	new_cmd = ft_strjoin("/", cmd);
	if (!new_cmd)
		return (NULL);
	new_path = ft_strjoin(path, new_cmd);
	if (!new_path)
	{
		free(new_cmd);
		return (NULL);
	}
	free(new_cmd);
	return (new_path);
}

int	is_valid(char *path, int flag)
{
	int	res;

	res = access(path, flag);
	return (res);
}

char	*return_path(char **env)
{
	char	*line;
	int		i;

	if (!env || !*env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		line = ft_strnstr(env[i], "PATH=", 5);
		if (line)
		{
			line = ft_strtrim(line, "PATH=");
			return (line);
		}
		i++;
	}
	return (NULL);
}

char	*free_enp(char **enp)
{
	int	i;

	if (!enp || !*enp)
		return (NULL);
	i = 0;
	while (enp[i])
	{
		free(enp[i]);
		i++;
	}
	free(enp);
	return (NULL);
}
/*
int	main(int ac, char *av[], char *env[])
{
	char	*res = build_path(env, "masooad");
	printf("valid: %s\n", res);
	free(res);
	char *paths = ft_strnstr(env[37], "PATH=",  5);
	printf("%s\n",paths);
	char *path = ft_strtrim(paths, "PATH=");
	printf("%s\n",path);
	char **spl = ft_split(path, ':');
	if (!spl)
		return (1);
	int i = 0;
	char	*path1;
	while (spl[i])
	{
		path1 = ft_strjoin(spl[i], "/ls");
		printf("\n%s\nAccess Found: %d\nAccess exec: %d", path1,
		 access(path1, F_OK), access(path1, X_OK));
		i++;
	}
}
*/
