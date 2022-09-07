/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:49:38 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/07 14:32:14 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	error_occurred(char *err_msg, t_window *data)
{
	ft_printf("%s\n", err_msg);
	flush_map(data);
	exit(0);
}

void	flush_map(t_window *data)
{
	size_t	i;

	i = 0;
	if (data->map.lines)
	{
		while (data->map.lines[i])
		{
			free(data->map.lines[i]);
			data->map.lines[i] = NULL;
			i++;
		}
		free(data->map.lines);
		data->map.lines = NULL;
	}
}
