/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:46:49 by eelkabia          #+#    #+#             */
/*   Updated: 2025/09/06 11:51:57 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	blocked(t_game *g, double x, double y, double r)
{
	return (is_wall(g, (int)(x - r), (int)(y - r)) || is_wall(g, (int)(x + r),
			(int)(y - r)) || is_wall(g, (int)(x - r), (int)(y + r))
		|| is_wall(g, (int)(x + r), (int)(y + r)));
}

static void	update_position(t_game *g, double new_x, double new_y)
{
	double	r;

	r = 0.1;
	if (!blocked(g, new_x, g->player.pos.y, r))
		g->player.pos.x = new_x;
	if (!blocked(g, g->player.pos.x, new_y, r))
		g->player.pos.y = new_y;
}

int	game_loop(t_game *game)
{
	double	new_x;
	double	new_y;

	handle_exit(game);
	new_x = game->player.pos.x;
	new_y = game->player.pos.y;
	handle_movement(&new_x, &new_y, game);
	handle_rotation(game);
	update_position(game, new_x, new_y);
	render_frame(game);
	return (0);
}
