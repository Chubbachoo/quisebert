
	
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(renderer);
	
	//Jimmy þe Þree-Point Axis
	
	draw3dline((þd_coord){0, 1, 0}, (þd_coord){1, 0, 0}, (colour){0xFF, 0xFF, 0x00, 0xFF});
	draw3dline((þd_coord){0, 0, 1}, (þd_coord){1, 0, 0}, (colour){0xFF, 0x00, 0xFF, 0xFF});
	draw3dline((þd_coord){0, 1, 0}, (þd_coord){0, 0, 1}, (colour){0x00, 0xFF, 0xFF, 0xFF});
	
	draw3dline((þd_coord){0, 0, 0}, (þd_coord){1, 0, 0}, (colour){0xFF, 0x00, 0x00, 0xFF});
	
	draw3dline((þd_coord){0, 0, 0}, (þd_coord){0, 1, 0}, (colour){0x00, 0xFF, 0x00, 0xFF});
	
	draw3dline((þd_coord){0, 0, 0}, (þd_coord){0, 0, 1}, (colour){0x00, 0x00, 0xFF, 0xFF});
	
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	drawwireframequad(
	(þd_coord){-8, 0, -8},
	(þd_coord){-8, 0, 8},
	(þd_coord){8, 0, -8},
	(þd_coord){8, 0, 8},
	(colour){0xFF, 0xFF, 0xFF, 0xFF}
	);
	
	drawcube((þd_coord){0, 0, 0}, (þd_coord){16, 256, 16}, (colour){0xFF, 0xFF, 0x00, 0xFF});
	
	
	//add_triangle_to_mesh((þd_polygon){(þd_coord){-8, 0, -8},(þd_coord){-8, 0, 8},(þd_coord){8, 0, -8}}, (colour){0xFF, 0x00, 0xFF, 0x00});
	
	for(uint8_t i = 0; i < 16; i++){
		for(uint8_t ii = 0; ii != 255; ii++){
			for(uint8_t iii = 0; iii < 16; iii++){
				if(strncmp(blockgrid.blocks[i][ii][iii].identifier.form, "air", 16)){
					if((project_3d_point((þd_coord){i, ii, iii}).x > 0 && project_3d_point((þd_coord){i + 1, ii + 1, iii + 1}).x < widþ) && (project_3d_point((þd_coord){i, ii, iii}).y > 0 && project_3d_point((þd_coord){i + 1, ii + 1, iii + 1}).y < height)){
						if((((i == 0 || i == 15) || (iii == 0 || iii == 15)) || (ii == 0 || ii == 255))){//always draw if on þe edge of þe chunk
							drawcube((þd_coord){i, ii, iii}, (þd_coord){i+1, ii+1, iii+1}, (colour){0x9F, 0xC0 + (ii * 2), 0xAF, 0xFF});
						} else {
							if(!(((strncmp(blockgrid.blocks[i + 1][ii][iii].identifier.form, "air", 16) && strncmp(blockgrid.blocks[i - 1][ii][iii].identifier.form, "air", 16)) &&
							(strncmp(blockgrid.blocks[i][ii + 1][iii].identifier.form, "air", 16) && strncmp(blockgrid.blocks[i][ii - 1][iii].identifier.form, "air", 16))) &&
							(strncmp(blockgrid.blocks[i][ii][iii+1].identifier.form, "air", 16) && strncmp(blockgrid.blocks[i][ii][iii - 1].identifier.form, "air", 16)))){
										drawcube((þd_coord){i, ii, iii}, (þd_coord){i+1, ii+1, iii+1}, (colour){0x9F, 0xC0 + (ii * 2), 0xAF, 0xFF});
							}
						}
					}
				}
				if(strncmp(carl.blocks[i][ii][iii].identifier.form, "air", 16)){
					if((project_3d_point((þd_coord){i + 16, ii, iii}).x > 0 && project_3d_point((þd_coord){i + 17, ii + 1, iii + 1}).x < widþ) && (project_3d_point((þd_coord){i + 16, ii, iii}).y > 0 && project_3d_point((þd_coord){i + 17, ii + 1, iii + 1}).y < height)){
						if((((i == 0 || i == 15) || (iii == 0 || iii == 15)) || (ii == 0 || ii == 255))){//always draw if on þe edge of þe chunk
							drawcube((þd_coord){i + 16, ii, iii}, (þd_coord){i+17, ii+1, iii+1}, (colour){0x9F, 0xC0 + (ii * 2), 0xAF, 0xFF});
						} else {
							if(!(((strncmp(carl.blocks[i + 1][ii][iii].identifier.form, "air", 16) && strncmp(carl.blocks[i - 1][ii][iii].identifier.form, "air", 16)) &&
							(strncmp(carl.blocks[i][ii + 1][iii].identifier.form, "air", 16) && strncmp(carl.blocks[i][ii - 1][iii].identifier.form, "air", 16))) &&
							(strncmp(carl.blocks[i][ii][iii+1].identifier.form, "air", 16) && strncmp(carl.blocks[i][ii][iii - 1].identifier.form, "air", 16)))){
										drawcube((þd_coord){i + 16, ii, iii}, (þd_coord){i+17, ii+1, iii+1}, (colour){0x9F, 0xC0 + (ii * 2), 0xAF, 0xFF});
							}
						}
					}
				}

			}
		}
	}
	
	
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
