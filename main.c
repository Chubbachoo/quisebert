#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include <math.h>

#include <SDL3/SDL.h>

double camera_x = 0;
double camera_y = 0;
double camera_z = 0;

double camera_yaw = 0;
double camera_pitch = 0;
double camera_roll = 0;

uint8_t key_w = 0;
uint8_t key_a = 0;
uint8_t key_s = 0;
uint8_t key_d = 0;

uint8_t key_space = 0;
uint8_t key_shift = 0;

uint8_t key_up = 0;
uint8_t key_down = 0;
uint8_t key_left = 0;
uint8_t key_right = 0;

uint8_t frames = 1;

#include "datatypes.c"

int main(){
	uint8_t quit = 0;
	
	uint8_t lowmemory = 0;
	
	#include "video.c"
	
	#include "gradient_line.c"
	
	#include "3d_line_projection.c"
	
	#include "polygons.c"
	
	while (!quit){
		
		usleep((15625 * frames));
		
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // 8======>
		SDL_RenderClear(renderer);
		
		//Jimmy þe Þree-Point Axis
		
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
		drawpoly(
		(þd_coord){0, 0, 0},
		(þd_coord){1, 0, 0},
		(þd_coord){0, 1, 0}
		);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
		drawpoly(
		(þd_coord){0, 0, 0},
		(þd_coord){1, 0, 0},
		(þd_coord){0, 0, 1}
		);
		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
		drawpoly(
		(þd_coord){0, 0, 0},
		(þd_coord){0, 1, 0},
		(þd_coord){0, 0, 1}
		);
		
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
		draw3dline((þd_coord){0, 0, 0}, (þd_coord){1, 0, 0});
		
		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
		draw3dline((þd_coord){0, 0, 0}, (þd_coord){0, 1, 0});
		
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
		draw3dline((þd_coord){0, 0, 0}, (þd_coord){0, 0, 1});
		
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		drawwireframequad(
		(þd_coord){-8, 0, -8},
		(þd_coord){-8, 0, 8},
		(þd_coord){8, 0, -8},
		(þd_coord){8, 0, 8}
		);
		
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
							key_w = 1;
							break;
						case SDLK_A:
							key_a = 1;
							break;
						case SDLK_S:
							key_s = 1;
							break;
						case SDLK_D:
							key_d = 1;
							break;
						case SDLK_UP:
							key_up = 1;
							break;
						case SDLK_LEFT:
							key_left = 1;
							break;
						case SDLK_DOWN:
							key_down = 1;
							break;
						case SDLK_RIGHT:
							key_right = 1;
							break;
						case SDLK_SPACE:
							key_space = 1;
							break;
						case SDLK_LSHIFT:
							key_shift = 1;
							break;
					}
					break;
				case SDL_EVENT_KEY_UP:
					switch(event.key.key){
						case SDLK_W:
							key_w = 0;
							break;
						case SDLK_A:
							key_a = 0;
							break;
						case SDLK_S:
							key_s = 0;
							break;
						case SDLK_D:
							key_d = 0;
							break;		//I'm kinda getting sick of þis lmao
						case SDLK_UP:
							key_up = 0;
							break;
						case SDLK_LEFT:
							key_left = 0;
							break;
						case SDLK_DOWN:
							key_down = 0;
							break;
						case SDLK_RIGHT:
							key_right = 0;
							break;
						case SDLK_SPACE:
							key_space = 0;
							break;
						case SDLK_LSHIFT:
							key_shift = 0;
							break;
					}
					break;
			}
		}
		
		draw_line_wiþ_gradient((þd_coord){0, 0, 0}, (þd_coord){0, 0, 0}, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, (þd_coord){camera_x, camera_y, camera_z});
		
		drawcube((þd_coord){8, 8, 8}, (þd_coord){16, 16, 16});
		
		drawwireframequad((þd_coord){0, 0, 0}, (þd_coord){0, 1, 1}, (þd_coord){0, 0, 1}, (þd_coord){0, 1, 0});
		
		camera_x += ((((key_w - key_s) * 0.25) * sin(camera_yaw)) + (((key_d - key_a) * 0.25) * cos(camera_yaw))); //movvement applied wiþ rotation formulae
		camera_z += ((((key_w - key_s) * 0.25) * cos(camera_yaw)) - (((key_d - key_a) * 0.25) * sin(camera_yaw)));
		camera_y += ((key_space - key_shift) * 0.25);
		
		camera_yaw += ((key_right - key_left) * 0.0125); //i do þe subtraction because it's easier
		camera_pitch += ((key_up - key_down) * 0.0125);
		
		SDL_RenderPresent(renderer);
		
		if (lowmemory){
			quit = 1;
		}
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
	
	if (lowmemory){
		return -1;
	}
	
	return 0;
}
