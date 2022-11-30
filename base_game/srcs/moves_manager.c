/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:44:32 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/30 22:15:37 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_game.h"

void	move_player(t_infos *infos)
{
	p_coords->x += infos->player->horizontal_acc / 2;
	if (infos->player->vertical_acc / 2 + p_coords->y < infos->mlx->height - PLAYER_SIZE)
		p_coords->y += infos->player->vertical_acc / 2;
	else
		p_coords->y = infos->mlx->height - PLAYER_SIZE;
	if (infos->player->horizontal_acc / 2 + p_coords->x < infos->mlx->width - PLAYER_SIZE)
		p_coords->x += infos->player->horizontal_acc / 2;
	else
		p_coords->x = infos->mlx->width - PLAYER_SIZE;
	if (infos->player->horizontal_acc / 2 + p_coords->x < 0)
		p_coords->x = 0;
}

void	hook_manager(int width, int height, void *param)
{
	t_infos	*infos;

	(void)width;
	infos = (t_infos *)param;
	p_coords->y = (size_t)height;
}

void	loop_manager(void *param)
{
	static	int cpt = 0;
	t_infos	*infos;

	infos = (t_infos *)param;
	if ((((!(D_KEY || RIGHT_KEY)) && (!(A_KEY || LEFT_KEY))) || (p_coords->x == 0 || p_coords->x == infos->mlx->width - 64)) && p_grounded)
	{
		if (infos->player->horizontal_acc > 0)
		{
			if (infos->player->horizontal_acc - 1 > 0)
				infos->player->horizontal_acc -= 1;
			else
				infos->player->horizontal_acc = 0;
		}
		else
		{
			if (infos->player->horizontal_acc + 1 < 0)
				infos->player->horizontal_acc += 1;
			else
				infos->player->horizontal_acc = 0;
		}
	}
	if (D_KEY || RIGHT_KEY)
	{
		if (infos->player->horizontal_acc <= 0)
			infos->player->horizontal_acc = X_SPEED;
		else if (infos->player->horizontal_acc + X_SPEED < X_MAXSPEED)
			infos->player->horizontal_acc += X_SPEED;
		else if (infos->player->horizontal_acc > X_MAXSPEED)
			infos->player->horizontal_acc -= (X_SPEED / 4);
		else 
			infos->player->horizontal_acc = X_MAXSPEED;
	}
	if (A_KEY || LEFT_KEY)
	{
		if (infos->player->horizontal_acc >= 0)
			infos->player->horizontal_acc = -X_SPEED;
		else if (infos->player->horizontal_acc - X_SPEED > -X_MAXSPEED)
			infos->player->horizontal_acc -= X_SPEED;
		else if (infos->player->horizontal_acc < -X_MAXSPEED)
			infos->player->horizontal_acc += (X_SPEED / 4);
		else 
			infos->player->horizontal_acc = -X_MAXSPEED;
	}
	move_player(infos);
	if (!p_grounded)
	{
		if (p_coords->x == 0 || p_coords->x == infos->mlx->width - PLAYER_SIZE)
			infos->player->double_jump = 1;
		if (p_coords->y == infos->mlx->height - PLAYER_SIZE)
		{
			infos->player->vertical_acc = 0;
			p_grounded = 1;
			infos->player->double_jump = 1;
		}
		else
			infos->player->vertical_acc += 10;
	}
	if (cpt++ == 5)
	{
		cpt = 0;
		print_player_stats(infos);
	}
	render_player(infos);
}

void	key_manager(mlx_key_data_t keydata, void *param)
{
	t_infos	*infos;

	infos = (t_infos *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		free(infos->mlx);
		free(infos->player->coords);
		free(infos->player);
		free(infos);
		exit(EXIT_SUCCESS);
	}
	if ((IS_SPACE || IS_UP || keydata.key == MLX_KEY_W) && !p_grounded && keydata.action == MLX_PRESS)
	{
		if (p_coords->x == 0)
		{
			if (infos->player->vertical_acc > 0)
				infos->player->vertical_acc -= (Y_SPEED / 2);
			else
				infos->player->vertical_acc = (-Y_SPEED / 2);
			infos->player->horizontal_acc = (X_MAXSPEED * 1.5);
		}
		else if (p_coords->x == infos->mlx->width - PLAYER_SIZE)
		{
			if (infos->player->vertical_acc > 0)
				infos->player->vertical_acc -= (Y_SPEED / 2);
			else
				infos->player->vertical_acc = (-Y_SPEED / 2);
			infos->player->horizontal_acc = -(X_MAXSPEED * 1.5);
		}
		else if (infos->player->double_jump)
		{
			infos->player->vertical_acc -= (Y_SPEED + infos->player->vertical_acc);
			infos->player->double_jump = 0;
		}	
	}
	else if ((IS_SPACE || IS_UP || IS_W) && p_grounded && IS_PRESSED)
	{
		if (p_coords->x == 0 || p_coords->x == infos->mlx->width - PLAYER_SIZE)
			infos->player->vertical_acc = -(Y_SPEED / 2);
		else
			infos->player->vertical_acc = -Y_SPEED;
		p_grounded = 0;
	}
}
