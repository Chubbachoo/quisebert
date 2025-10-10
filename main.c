#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <uchar.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include <math.h>

#include <SDL3/SDL.h>

#include "debug.c"

#include "datatypes.c"
#include "qmaþlib.c"

double camera_x = 0;
double camera_y = 128;
double camera_z = 0;

double camera_yaw = 0;
double camera_pitch = 0;
double camera_roll = 0;

þd_rotating_world_point camera = {
		(int64_t) 0,
		(double) 0,
		(int64_t) 0,
		(double) 128,
		(int64_t) 0,
		(double) 0,
		
		(double) 0,
		(double) 0,
		(double) 0
	};

uint8_t key_move_forward = 0;
uint8_t key_move_left = 0;
uint8_t key_move_backwards = 0;
uint8_t key_move_right = 0;

uint8_t key_jump = 0;
uint8_t key_sprint = 0;

uint8_t key_look_up = 0;
uint8_t key_look_down = 0;
uint8_t key_look_left = 0;
uint8_t key_look_right = 0;

uint8_t frames = 1;

uint16_t widþ = 640;
uint16_t height = 480;

#include "mesh.c"

#include "blockgrid.c"

int main(){
	srand(0);
	uint8_t quit = 0;
	
	uint8_t lowmemory = 0;
	
	#include "video.c"
	
	#include "gradient_line.c"
	
	#include "3d_point_projection.c"
	#include "3d_line_projection.c"
	
	#include "polygons.c"
	
	#include "raster_definitions.c"
	
	struct timeval frame_start_time;
	struct timeval sleep_end_time;
	struct timeval sleep_end_delta_time;
	struct timeval logic_end_time;
	struct timeval logic_end_delta_time;
	struct timeval screen_draw_end_time;
	struct timeval screen_draw_end_delta_time;
	
	static qb_chunk blockgrid;
	static qb_chunk carl;
	
	worldgen(&blockgrid, 0, 0, 0);
	worldgen(&carl,  1, 0, 0);
	
	þd_rotating_world_point player = {
		(int64_t) 0,
		(double) 0,
		(int64_t) 0,
		(double) 128,
		(int64_t) 0,
		(double) 0,
		
		(double) 0,
		(double) 0,
		(double) 0
	};
	
	while (!quit){
		
		
		gettimeofday(&frame_start_time, NULL);
		
		usleep((15625 * frames));
		
		gettimeofday(&sleep_end_time, NULL);
		timersub(&sleep_end_time, &frame_start_time, &sleep_end_delta_time);
		
		SDL_Event event;
		while (SDL_PollEvent(&event)){
			switch (event.type){
				case SDL_EVENT_TERMINATING:
					quit = 1;
					break;
				case SDL_EVENT_LOW_MEMORY:
					lowmemory = 1;
					break;
				case SDL_EVENT_QUIT:
					quit = 1;
					break;
				case SDL_EVENT_KEY_DOWN:
					switch(event.key.key){
						case SDLK_ESCAPE:
							quit = 1;
							break;
						case SDLK_W:
							key_move_forward = 1;
							break;
						case SDLK_A:
							key_move_left = 1;
							break;
						case SDLK_S:
							key_move_backwards = 1;
							break;
						case SDLK_D:
							key_move_right = 1;
							break;
						case SDLK_UP:
							key_look_up = 1;
							break;
						case SDLK_LEFT:
							key_look_left = 1;
							break;
						case SDLK_DOWN:
							key_look_down = 1;
							break;
						case SDLK_RIGHT:
							key_look_right = 1;
							break;
						case SDLK_SPACE:
							key_jump = 1;
							break;
						case SDLK_LSHIFT:
							key_sprint = 1;
							break;
					}
					break;
				case SDL_EVENT_KEY_UP:
					switch(event.key.key){
						case SDLK_W:
							key_move_forward = 0;
							break;
						case SDLK_A:
							key_move_left = 0;
							break;
						case SDLK_S:
							key_move_backwards = 0;
							break;
						case SDLK_D:
							key_move_right = 0;
							break;		//I'm kinda getting sick of þis lmao
						case SDLK_UP:
							key_look_up = 0;
							break;
						case SDLK_LEFT:
							key_look_left = 0;
							break;
						case SDLK_DOWN:
							key_look_down = 0;
							break;
						case SDLK_RIGHT:
							key_look_right = 0;
							break;
						case SDLK_SPACE:
							key_jump = 0;
							break;
						case SDLK_LSHIFT:
							key_sprint = 0;
							break;
					}
					break;
			}
		}
		
		player = qmaþ_add_rotating_world_point_and_coord(player, (þd_coord){
			((((key_move_forward - key_move_backwards) * 0.25) * sin(camera_yaw)) + (((key_move_right - key_move_left) * 0.25) * cos(camera_yaw))),
			((key_jump - key_sprint) * 0.25),
			((((key_move_forward - key_move_backwards) * 0.25) * cos(camera_yaw)) - (((key_move_right - key_move_left) * 0.25) * sin(camera_yaw)))
		});
		player = qmaþ_add_rotating_world_point_and_angle(player, (þd_angle){
			((key_look_right - key_look_left) * 0.0125),
			((key_look_up - key_look_down) * 0.0125),
			0
		});
		camera = qmaþ_add_rotating_world_point_and_coord(player, (þd_coord){
			0,
			qmaþ_convert_m_to_blocks(1.64),
			0
		});
		
		camera_x = qmaþ_convert_rotating_world_point_to_rotating_point(camera).x;
		camera_y = qmaþ_convert_rotating_world_point_to_rotating_point(camera).y;
		camera_z = qmaþ_convert_rotating_world_point_to_rotating_point(camera).z;
		
		camera_yaw = qmaþ_convert_rotating_world_point_to_rotating_point(camera).yaw;
		camera_pitch = qmaþ_convert_rotating_world_point_to_rotating_point(camera).pitch;
		camera_roll = qmaþ_convert_rotating_world_point_to_rotating_point(camera).roll;
		
		if (lowmemory){
			quit = 1;
		}
		
		gettimeofday(&logic_end_time, NULL);
		timersub(&logic_end_time, &frame_start_time, &logic_end_delta_time);
		
		#include "drawscreen.c"
	}
	
	þd_coord test = qmaþ_convert_world_coord_to_coord((þd_world_coord){1, 1, 1, 1, 1, 1});
	
	printf("%f, %f, %f\n", test.x, test.y, test.z);
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
	
	if (lowmemory){
		return -1;
	}
	
	return 0;
}
