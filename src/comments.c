
// void	up_square(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1) {
// 		map->map_3d[map->x_max][map->y_max] += 1;
// 		map->map_3d[map->x_max][map->y_max + 1] += 1;
// 		map->map_3d[map->x_max + 1][map->y_max] += 1;
// 		map->map_3d[map->x_max + 1][map->y_max + 1] += 1;
// 	}
// }

// void	up_corner(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1)
// 		map->map_3d[map->x_max][map->y_max] += 0.5;
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
