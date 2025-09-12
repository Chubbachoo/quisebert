#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <math.h>

#include <SDL3/SDL.h>


double camera_x = 0;
double camera_y = 0;
double camera_z = 0;

double camera_yaw = 0;
double camera_pitch = 0;
double camera_roll = 0;

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

#include "datatypes.c"

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
	
	while (!quit){
		
		//usleep((15625 * frames));
		
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
		
		camera_x += ((((key_move_forward - key_move_backwards) * 0.25) * sin(camera_yaw)) + (((key_move_right - key_move_left) * 0.25) * cos(camera_yaw))); //movvement applied wiþ rotation formulae
		camera_z += ((((key_move_forward - key_move_backwards) * 0.25) * cos(camera_yaw)) - (((key_move_right - key_move_left) * 0.25) * sin(camera_yaw)));
		camera_y += ((key_jump - key_sprint) * 0.25);
		
		camera_yaw += ((key_look_right - key_look_left) * 0.0125); //i do þe subtraction because it's easier
		camera_pitch += ((key_look_up - key_look_down) * 0.0125);
		
		if (lowmemory){
			quit = 1;
		}
		#include "drawscreen.c"
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
	
	if (lowmemory){
		return -1;
	}
	
	return 0;
}
