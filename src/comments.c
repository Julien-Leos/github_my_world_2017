
// void	up_square(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1) {
// 		map->map_3d[map->x_max][map->y_max] += 1;
// 		map->map_3d[map->x_max][map->y_max + 1] += 1;
// 		map->map_3d[map->x_max + 1][map->y_max] += 1;
// 		map->map_3d[map->x_max + 1][map->y_max + 1] += 1;
// 	}
// }

// void	up_corner_brush(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1)
// 		map->map_3d[map->x_max][map->y_max] += 0.3;
// }
//
// void	down_square_brush(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1) {
// 		map->map_3d[map->x_max][map->y_max] -= 0.5;
// 		map->map_3d[map->x_max][map->y_max + 1] -= 0.5;
// 		map->map_3d[map->x_max + 1][map->y_max] -= 0.5;
// 		map->map_3d[map->x_max + 1][map->y_max + 1] -= 0.5;
// 	}
// }
//
// void	which_select_corner(window_t *win, map_t *map, int i, int j)
// {
// 	if (map->map_2d[i][j].x > win->mouse_pos.x - (SCALING_X * map->zoom / 3) &&
// 	map->map_2d[i][j].x < win->mouse_pos.x + (SCALING_X * map->zoom / 3) &&
// 	map->map_2d[i][j].y > win->mouse_pos.y - (SCALING_Y * map->zoom / 3) &&
// 	map->map_2d[i][j].y < win->mouse_pos.y + (SCALING_Y * map->zoom / 3) &&
// 	is_mouse_on_toolbox(win->mouse_pos) == 0) {
// 		map->x_max = (i > map->x_max) ? i : map->x_max;
// 		map->y_max = (j > map->y_max) ? j : map->y_max;
// 	}
// }
//
// void	select_corner(window_t *win, map_t *map)
// {
// 	sfVector2f circle_pos = {0, 0};
//
// 	map->x_max = -1;
// 	map->y_max = -1;
// 	for (int i = 0; i < map->map->map_x; i++)
// 		for (int j = 0; j < map->map->map_y; j++)
// 			which_select_corner(win, map, i, j);
// 	if (map->x_max != -1 && map->y_max != -1) {
// 		circle_pos.x = map->map_2d[map->x_max][map->y_max].x - 5;
// 		circle_pos.y = map->map_2d[map->x_max][map->y_max].y - 5;
// 		draw_square(win->window, map->mouse_circle, circle_pos);
// 	}
// }

// void	change_tool(obj_t *obj)
// {
// 	obj->num_tool += 1;
// 	if (obj->num_tool > 2)
// 		obj->num_tool = 1;
// }
//
// void	change_brush(obj_t *obj)
// {
// 	obj->num_brush += 1;
// 	if (obj->num_brush > 1)
// 		obj->num_brush = 0;
// }

// void	down_corner_brush(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1)
// 		map->map_3d[map->x_max][map->y_max] += 0.3;
// }
//
// void	down_tool_brush(map_t *map, obj_t *obj)
// {
// 	if (obj->num_tool == 0)
// 		down_corner_brush(map);
// 	else if (obj->num_tool == 1)
// 		down_square_brush(map);
// }

// void	up_square_brush(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1) {
// 		map->map_3d[map->x_max][map->y_max] += 0.3;
// 		map->map_3d[map->x_max][map->y_max + 1] += 0.3;
// 		map->map_3d[map->x_max + 1][map->y_max] += 0.3;
// 		map->map_3d[map->x_max + 1][map->y_max + 1] += 0.3;
// 	}
// }

// void	up_corner(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1)
// 		map->map_3d[map->x_max][map->y_max] += 0.5;
// }

// void	select_square(window_t *win, map_t *map)
// {
// 	sfVector2f circle_pos = {0, 0};
//
// 	map->x_max = -1;
// 	map->y_max = -1;
// 	if (map->rotation >= 0 && map->rotation < 90)
// 		for (int j = map->map->map_y - 1; j >= 0; j--)
// 			for (int i = 0; i <= map->map->map_x - 1; i++)
// 				which_select_square(win, map, i, j);
// 	if (map->rotation >= 90 && map->rotation < 180)
// 		for (int i = map->map->map_x - 1; i >= 0; i--)
// 			for (int j = map->map->map_y - 1; j >= 0; j--)
// 				which_select_square(win, map, i, j);
// 	if (map->rotation >= 180 && map->rotation < 270)
// 		for (int j = 0; j < map->map->map_y - 1 ; j++)
// 			for (int i = map->map->map_x - 1; i >= 0; i--)
// 				which_select_square(win, map, i, j);
// 	if (map->rotation >= 270 && map->rotation <= 360)
// 		for (int i = 0; i < map->map->map_x - 1; i++)
// 			for (int j = 0; j < map->map->map_y - 1 ; j++)
// 				which_select_square(win, map, i, j);
// 	if (map->x_max >= 0 && map->x_max < map->map->map_x && map->y_max >= 0 && map->y_max < map->map->map_y) {
// 		circle_pos.x = map->map_2d[map->x_max][map->y_max].x - 5;
// 		circle_pos.y = map->map_2d[map->x_max][map->y_max].y - 5;
// 		draw_square(win->window, map->mouse_circle, circle_pos);
// 		circle_pos.x = map->map_2d[map->x_max][map->y_max + 1].x - 5;
// 		circle_pos.y = map->map_2d[map->x_max][map->y_max + 1].y - 5;
// 		draw_square(win->window, map->mouse_circle, circle_pos);
// 		circle_pos.x = map->map_2d[map->x_max + 1][map->y_max].x - 5;
// 		circle_pos.y = map->map_2d[map->x_max + 1][map->y_max].y - 5;
// 		draw_square(win->window, map->mouse_circle, circle_pos);
// 		circle_pos.x = map->map_2d[map->x_max + 1][map->y_max + 1].x - 5;
// 		circle_pos.y = map->map_2d[map->x_max + 1][map->y_max + 1].y - 5;
// 		draw_square(win->window, map->mouse_circle, circle_pos);
// 	}
// }

// void	down_square(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1) {
// 		map->map_3d[map->x_max][map->y_max] -= 0.5;
// 		map->map_3d[map->x_max][map->y_max + 1] -= 0.5;
// 		map->map_3d[map->x_max + 1][map->y_max] -= 0.5;
// 		map->map_3d[map->x_max + 1][map->y_max + 1] -= 0.5;
// 	}
// }

// void	down_corner(map_t *map)
// {
// 	if (map->x_max != -1)
// 		map->map_3d[map->x_max][map->y_max] -= 0.5;
// }

// void	up_tool(map_t *map, obj_t *obj)
// {
// 	if (obj->num_tool == 0)
// 		up_corner(map);
// 	else if (obj->num_tool == 1)
// 		up_square(map);
// }

// void	down_tool(map_t *map, obj_t *obj)
// {
// 	if (obj->num_tool == 0)
// 		down_corner(map);
// 	else if (obj->num_tool == 1)
// 		down_square(map);
// }
