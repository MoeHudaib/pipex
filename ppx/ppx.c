/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:21:51 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/05 18:23:29 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppx.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	first_child(int *pipefd, char **env, char *cmd, t_fd *fd)
{
	char	**args;
	char	*path;

	dup2(fd->fd_in, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fd->fd_in);
	close(pipefd[0]);
	close(pipefd[1]);
	args = ft_split(cmd, ' ');
	if (!args)
	{
		close(fd->fd_out);
		exit(1);
	}
	path = build_path(env, args[0]);
	if (path)
		execve(path, args, env);
	path = ft_strjoin(cmd, " : command not found\n");
	if (path)
	{
		write(2, path, ft_strlen(path));
		free(path);
	}
	close(fd->fd_out);
	free_enp(args);
	exit(EXIT_FAILURE);
}

void	second_child(int *pipefd, char **env, char *cmd, t_fd *fd)
{
	char	**args;
	char	*path;

	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd->fd_out, STDOUT_FILENO);
	close(fd->fd_out);
	close(pipefd[0]);
	close(pipefd[1]);
	args = ft_split(cmd, ' ');
	if (!args)
	{
		close(fd->fd_in);
		exit(1);
	}
	path = build_path(env, args[0]);
	if (path)
		execve(path, args, env);
	path = ft_strjoin(cmd, " : command not found\n");
	if (path)
	{
		write(2, path, ft_strlen(path));
		free(path);
	}
	close(fd->fd_in);
	free_enp(args);
	exit(EXIT_FAILURE);
}

int	open_infile(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror(path);
		exit(1);
	}
	return (fd);
}

int	open_outfile(char *path, int fd_in)
{
	int	fd;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		close(fd_in);
		perror(path);
		exit(1);
	}
	return (fd);
}
