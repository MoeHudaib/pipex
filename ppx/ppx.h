/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:21:34 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/05 18:23:16 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPX_H
# define PPX_H

# include "../parse/parse.h"
# include <fcntl.h>

typedef struct s_fd
{
    int fd_in;
    int fd_out;
}   t_fd;

int		open_outfile(char *path, int fd_in);
int		open_infile(char *path);
void	second_child(int *pipefd, char **env, char *cmd, t_fd *fd);
void	first_child(int *pipefd, char **env, char *cmd, t_fd *fd);

#endif
