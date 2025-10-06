/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:23:47 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/05 18:24:05 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ppx/ppx.h"

int	main(int ac, char **av, char **env)
{
	int	pipefd[2];
	int	fd_in;
	int	fd_out;
	int	pid[2];

	if (ac != 5)
		return (write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40), 1);
	fd_in = open_infile(av[1]);
	fd_out = open_outfile(av[4]);
	if (fd_in == -1 || fd_out == -1 || pipe(pipefd) == -1)
		return (1);
	pid[0] = fork();
	if (pid[0] == 0)
		first_child(pipefd, fd_in, env, av[2]);
	pid[1] = fork();
	if (pid[1] == 0)
		second_child(pipefd, fd_out, env, av[3]);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd_in);
	close(fd_out);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}