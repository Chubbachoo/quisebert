
	double dot_product(td_coord vector1, td_coord vector2){
		return(vector1.x * vector2.x + vector1.y * vector2.y);
	}
	td_coord perpendiculate(td_coord vector){
		return((td_coord){vector.y, -vector.x});
	}
	uint8_t is_point_sidewards(td_coord line1, td_coord line2, td_coord point){
		td_coord moved_point = (td_coord){point.x - line1.x, point.y - line1.y};
		td_coord perp_line = perpendiculate((td_coord){line2.x - line1.x, line2.y - line1.y});
		return((dot_product(moved_point, perp_line) >= 0));
	}
	
	uint8_t point_in_triangle(td_coord point, td_polygon triangle){
		return (is_point_sidewards(triangle.point1, triangle.point2, point) && is_point_sidewards(triangle.point2, triangle.point3, point) && is_point_sidewards(triangle.point3, triangle.point1, point));
	}
	
	//my friend always seems to follow what sebastian lague does
	//Now I am.
	//Huh.
	int rasterscreen(){
		uint8_t random = (uint8_t)(rand());
		uint16_t ii_y;
		for(uint16_t i_x = 0; i_x < widþ; i_x++){
			for(uint16_t ii_y = 0; ii_y < widþ; ii_y++){
				random = (uint8_t)(rand());
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				if(point_in_triangle((td_coord){i_x, ii_y}, (td_polygon){(td_coord){0, 0},(td_coord){0, 100},(td_coord){100, 0}})){
					SDL_RenderPoint(renderer, i_x, ii_y);
				}
			}
		}
	}
