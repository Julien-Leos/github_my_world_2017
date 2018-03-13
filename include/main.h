	/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <SFML/Graphics.h>
	#include <SFML/Window.h>
	#include <SFML/Audio.h>
	#include <SFML/System.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <math.h>

	#define RW_DVA	sfRenderWindow_drawVertexArray
	#define RW_PE sfRenderWindow_pollEvent
	#define RW_DRS sfRenderWindow_drawRectangleShape
	#define RG sfColor_fromRGB
	#define COL sfColor
	#define V2I sfVector2i
	#define V2F sfVector2f
	#define RS_SETPOS sfRectangleShape_setPosition
 	#define SCALING_X 45
	#define SCALING_Y 45
	#define SCALING_Z 20

	typedef struct brush_s {
		int brush_max_x;
		int brush_max_y;
		int brush_radius;
		float brush_strength;
		float brush_altitude;
		sfCircleShape *brush_circle;
	} brush_t;

	typedef struct settings_s {
		double inclinaison;
		double rotation;
		int offset_x;
		int offset_y;
		float zoom;
	} settings_t;

	typedef struct map_s {
		sfVector2f **map_2d;
		float **map_3d;
		int map_x;
		int map_y;
		int display_lines;
		sfColor ***color_tab;
		sfTexture **texture_tab;
	} map_t;

	typedef struct obj_s {
		sfSprite *sprite;
		sfTexture *text;
		sfVector2f pos;
		int num_button;
		int num_tool;
	} obj_t;

	typedef struct button_s {
		sfRectangleShape *rect;
		sfRectangleShape *text_one;
		sfRectangleShape *text_two;
		sfRectangleShape *text_three;
		sfRectangleShape *text_four;
	}button_t;

	typedef struct window_s {
		sfRenderWindow *window;
		sfEvent event;
		sfVector2i mouse_pos;
		char *input;
		sfText *textbox;
		sfText *textbox_ex;
		sfFont *font;
		int textok;
	} window_t;

	typedef struct all_s {
		button_t *button;
		settings_t *stg;
		brush_t *brs;
		map_t *map;
		obj_t *obj;
		window_t *win;
	} all_t;

	/* -------------------------- BRUSH TOOLS -------------------------- */
	int	is_brush_max_valid(brush_t *, map_t *);
	float	is_brush_equation_valid(brush_t *, int, int);
	void	which_brush(map_t *, obj_t *, brush_t *);

	/* ----------------------------- BRUSH ----------------------------- */
	void	select_brush_corner(all_t *, int, int);
	void	display_brush(all_t *);
	void	level_brush(map_t *, brush_t *);
	void	up_brush(map_t *, brush_t *);
	void	down_brush(map_t *, brush_t *);




	float	**create_perlin_map(map_t *map);
	unsigned int	*generate_randomised_tab(void);
	float	my_getfloat(char *str);
	void	increase_rotation(settings_t *stg);
	void	increase_inclinaison(settings_t *stg);
	void	increase_zoom(settings_t *stg);
	void	increase_strength(brush_t *brs);
	void	increase_radius(brush_t *brs);
	void	decrease_inclinaison(settings_t *stg);
	void	decrease_rotation(settings_t *stg);
	void	decrease_zoom(settings_t *stg);
	void	decrease_strength(brush_t *brs);
	void	decrease_radius(brush_t *brs);
	int my_strlen(char *str);
	int load_resize(sfVector2i old_map, map_t *map);
	void reset(map_t *map, settings_t *stg);
	void text_enter(int *new_x, int *new_y, window_t *win);
	void enter_input(all_t *all, settings_t *stg, int *i, int *box);
	void	init_coord_max(map_t *map, settings_t *stg, brush_t *);
	void	brush_nivelling(map_t *map, brush_t *);
	float	get_perlin_noise_value(float x, float y, unsigned int *perm);
	void draw_2d_map(sfRenderWindow *, map_t *, settings_t *);
	sfVertexArray *create_line(sfVector2f *, sfVector2f *);
	sfVertexArray *create_quads(sfVector2f **vector_tab, sfColor color);
	sfVector2f project_iso_point(sfVector3f, settings_t *, map_t *);
	sfVector2f **create_2d_map(float **, map_t *, settings_t *);
	float **create_3d_map(map_t*);
	obj_t create_object(sfVector2f, char *, sfVector2f);
	void init_toolbox(all_t *all);
	int buttonIsClicked(obj_t *, sfVector2i, int);
	char *my_itoa(float);
	int save(all_t *);
	char *get_next_line(int);
	int my_getnbr(char *);
	int load(all_t *);
	void draw_circle(sfRenderWindow *win, sfCircleShape *circle, sfVector2f pos);
	void	select_corner_on_mouse(all_t *, int, int);
	void	init_obj(obj_t *obj);
	void	init_map(map_t *map, settings_t *);
	void	init_window(window_t *win);
	void	init_all(all_t *all);
	void	rotation_0_to_90(map_t *map, sfRenderWindow *win, sfRenderStates *st);
	void	rotation_90_to_180(map_t *map, sfRenderWindow *win, sfRenderStates *st);
	void	rotation_180_to_270(map_t *map, sfRenderWindow *win, sfRenderStates *st);
	void	rotation_270_to_360(map_t *map, sfRenderWindow *win, sfRenderStates *st);
	void	draw_quads(map_t *map, sfRenderWindow *win, sfRenderStates *st, V2I crd);
	void event(all_t *all, window_t *win, map_t *map, settings_t *stg);
	void event_scrolled(window_t *win, settings_t *);
	void event_brush(all_t *all, map_t *map);
	void event_button(all_t *all, window_t *win, int *box);
	int	is_mouse_on_toolbox(sfVector2i mouse_pos);
	float	calc_sqr(sfVector2f A, sfVector2f B, sfVector2i P);
	char	*my_revstr (char *str);
	int	my_power(int nb, int power);
	int check_if_argv_is_save(char **argv);
	int	textbox(all_t *, window_t *win, settings_t *, int *box);
	void	my_free(all_t *all);
	int check_argv(char **argv, all_t *all);
	void	which_button(window_t *win, obj_t *obj);
	void	draw_toolbox(window_t *win, obj_t *obj, button_t *button);
	void	terraforming(all_t *, window_t *win, map_t *map, settings_t *);
	void	draw_window(window_t *win);
	void event_keys(window_t *win, settings_t *, brush_t *, int *box);
	sfRenderWindow *my_window_create(void);
	int my_putstrfd(int fd, char *str);
	void switch_tools(all_t *all);
	void switch_tools2(all_t *all);
	void init_color_tab(map_t *map);
	void enter_input(all_t *all, settings_t *stg, int *i, int *box);
	int my_printf(char *s, ...);
	int check_input(window_t *win, int *i, int *box);
#endif
