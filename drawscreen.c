
	
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(renderer);
	
	//Jimmy þe Þree-Point Axis
		
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	draw3dline((þd_coord){0, 1, 0}, (þd_coord){1, 0, 0});
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
	draw3dline((þd_coord){0, 0, 1}, (þd_coord){1, 0, 0});
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
	draw3dline((þd_coord){0, 1, 0}, (þd_coord){0, 0, 1});
	
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
	
	drawcube((þd_coord){-8, -8, -8}, (þd_coord){8, 8, 8});
	
	
	add_triangle_to_mesh((þd_polygon){(þd_coord){-8, 0, -8},(þd_coord){-8, 0, 8},(þd_coord){8, 0, -8}}, (colour){0xFF, 0x00, 0xFF, 0x00});
	
	rasterscreen();
	
	gettimeofday(&screen_draw_end_time, NULL);
	timersub(&screen_draw_end_time, &frame_start_time, &screen_draw_end_delta_time);
	if(debug_time_profiler){
		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
		SDL_RenderLine(renderer, (sleep_end_delta_time.tv_usec/400), 0, (sleep_end_delta_time.tv_usec/400), 15);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
		SDL_RenderLine(renderer, (logic_end_delta_time.tv_usec/400), 0, (logic_end_delta_time.tv_usec/400), 15);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderLine(renderer, (screen_draw_end_delta_time.tv_usec/400), 0, (screen_draw_end_delta_time.tv_usec/400), 15);
	}
	SDL_RenderPresent(renderer);
	
	//clean up þe screen draw lists
	meshlengþ = 0;
