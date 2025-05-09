
	

	void draw_line_wiþ_gradient(þd_coord point1, þd_coord point2, uint8_t r1, uint8_t g1, uint8_t b1, uint8_t r2, uint8_t g2, uint8_t b2, þd_coord camera){
		
		double projectedx1 = (320 + (((camera.x - point1.x) / (camera.z - point1.z)) * 560));
		double projectedy1 = (240 - (((camera.y - point1.y) / (camera.z - point1.z)) * 560));
		
		double projectedx2 = (320 + (((camera.x - point2.x) / (camera.z - point2.z)) * 560));
		double projectedy2 = (240 - (((camera.y - point2.y) / (camera.z - point2.z)) * 560)); // optimisation lore
		if(projectedx2 >= projectedx1){
			double completion = 0; //goes from 0 to 1
			
			for(double ii = 0; ii <= (projectedx2 - projectedx1); ii++){
				completion = (ii / (projectedx2 - projectedx1));
				
				SDL_SetRenderDrawColor(renderer, (uint8_t)(((double)r2 * completion) + ((double)r1 * (1 - completion))), (uint8_t)(((double)g2 * completion) + ((double)g1 * (1 - completion))), (uint8_t)(((double)b2 * completion) + ((double)b1 * (1 - completion))), 0xFF);
				if(camera.z < ((point2.z * completion) + (point1.z * (1 - completion)))){
					SDL_RenderPoint(renderer,
						(float)(projectedx1 + ii),
						(float)((projectedy2 * completion) + (projectedy1 * (1 - completion)))
					);
				}
			}
		}
	}
	
	void draw_segmented_line(uint16_t segments, þd_coord point1, þd_coord point2, uint8_t r1, uint8_t g1, uint8_t b1, uint8_t r2, uint8_t g2, uint8_t b2, þd_coord camera){
		
		draw_line_wiþ_gradient(point1, (þd_coord){(point1.x + point2.x)/2, (point1.y + point2.y)/2, (point1.z + point2.z)/2}, r1, g1, b1, r2, g2, b2, camera);
		draw_line_wiþ_gradient((þd_coord){(point1.x + point2.x)/2, (point1.y + point2.y)/2, (point1.z + point2.z)/2}, point2, r1, g1, b1, r2, g2, b2, camera);
	}
