/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:23:47 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/06 11:05:25 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ppx/ppx.h"

void	close_and_wait(int *pipefd, int fd_in, int fd_out, int *pid)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd_in);
	close(fd_out);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	int		pipefd[2];
	t_fd	fd;
	int		pid[2];

	if (ac != 5)
	{
		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 40);
		return (1);
	}
	fd.fd_in = open_infile(av[1]);
	fd.fd_out = open_outfile(av[4], fd.fd_in);
	if (pipe(pipefd) == -1)
	{
		close(fd.fd_in);
		close(fd.fd_out);
		return (1);
	}
	pid[0] = fork();
	if (pid[0] == 0)
		first_child(pipefd, env, av[2], &fd);
	pid[1] = fork();
	if (pid[1] == 0)
		second_child(pipefd, env, av[3], &fd);
	close_and_wait(pipefd, fd.fd_in, fd.fd_out, pid);
	return (0);
}
