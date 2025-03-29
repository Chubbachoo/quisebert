
	void draw_line_wiþ_gradient(þd_coord point1, þd_coord point2, uint8_t r1, uint8_t g1, uint8_t b1, uint8_t r2, uint8_t g2, uint8_t b2, þd_coord camera){
		if(point2.x >= point1.x){
			double completion = 0; //goes from 0 to 1
			for(double i = 0; i <= (point2.x - point1.x); i++){
				completion = (i / (point2.x - point1.x));
				SDL_SetRenderDrawColor(renderer, (uint8_t)(((double)r2 * completion) + ((double)r1 * (1 - completion))), 0x00, 0x00, 0xFF);
				if(camera.z < ((point2.z * completion) + (point1.z * (1 - completion)))){
					SDL_RenderPoint(renderer,
						(float)(point1.x + i),
						(float)((point2.y * completion) + (point1.y * (1 - completion)))
					);
				}
			}
		}
	}
