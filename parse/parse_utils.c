/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:08:07 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/06 11:12:04 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*find_valid_path(char **dirs, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (dirs && dirs[i])
	{
		path = try_path(cmd, dirs[i]);
		if (!path)
			return (NULL);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_enp(dirs);
			return (path);
		}
		free(path);
		i++;
	}
	free_enp(dirs);
	return (NULL);
}

char	*build_path(char **env, char *cmd)
{
	char	*path_line;
	char	**dirs;
	char	*path;

	if (!env || !cmd)
		return (NULL);
	path_line = return_path(env);
	if (!path_line)
		return (NULL);
	dirs = ft_split(path_line, ':');
	free(path_line);
	if (!dirs)
		return (NULL);
	path = find_valid_path(dirs, cmd);
	if (!path)
	{
		free_enp(dirs);
		return (NULL);
	}
	return (path);
}
