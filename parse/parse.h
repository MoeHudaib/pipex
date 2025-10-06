/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:04:30 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/06 11:10:05 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/*			
 R_OK (read permission)
 W_OK (write permission)
 X_OK (execute/search permission)
 F_OK (existence test)
 */
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include "../libs/libft/libft.h"

char	*build_path(char **env, char *cmd);
char	*free_enp(char **enp);
char	*try_path(char *cmd, char *path);
int		is_valid(char *path, int flag);
char	*return_path(char **env);

#endif
