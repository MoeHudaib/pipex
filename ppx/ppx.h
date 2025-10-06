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

int		open_outfile(char *path);
int		open_infile(char *path);
void	second_child(int *pipefd, int fd_out, char **env, char *cmd);
void	first_child(int *pipefd, int fd_in, char **env, char *cmd);

#endif
