/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:04:30 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/05 16:05:19 by mhdeeb           ###   ########.fr       */
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

#endif
