
	
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
	
	
	rasterscreen();
	
	SDL_RenderPresent(renderer);
