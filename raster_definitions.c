
	uint16_t i_y;
	uint16_t ii_x;
	
	uint8_t is_point_sidewards(td_coord line1, td_coord line2, td_coord point){
		return(((point.x - line1.x)*(line2.y - line1.y)) - ((point.y - line1.y)*(line2.x - line1.x)) >= 0);
	}
	
	uint8_t point_in_triangle(td_coord point, td_polygon triangle){
		float smally = fmin(fmin(triangle.point1.y, triangle.point2.y), triangle.point3.y);
		float smallx = fmin(fmin(triangle.point1.x, triangle.point2.x), triangle.point3.x);
		float bigy = fmax(fmax(triangle.point1.y, triangle.point2.y), triangle.point3.y);
		float bigx = fmax(fmax(triangle.point1.x, triangle.point2.x), triangle.point3.x);
		if(smallx <= point.x <= bigx && smally <= point.y < bigy){
			return (is_point_sidewards(triangle.point1, triangle.point2, point) == is_point_sidewards(triangle.point2, triangle.point3, point) && is_point_sidewards(triangle.point2, triangle.point3, point) == is_point_sidewards(triangle.point3, triangle.point1, point));
		}
		return 0;
	}
	
	void binarysearchtriangle(uint16_t size){
		ii_x += size;
		if(!(point_in_triangle((td_coord){ii_x, i_y}, (td_polygon){(td_coord){100, 0},(td_coord){0, 0},(td_coord){10, 50}})) || ii_x > widþ){
			ii_x -= size;
		}
		if(size > 1){
			binarysearchtriangle((uint16_t)(ceil(size/2)));
		}
	}
	
	//my friend always seems to follow what sebastian lague does
	//Now I am.
	//Huh.
	int rasterscreen(){
		uint8_t random = (uint8_t)(rand());
		uint16_t storedx;
		uint16_t storedy;
		for(i_y = 0; i_y < height; i_y++){
			for(ii_x = 0; ii_x < widþ; ii_x++){
				random = (uint8_t)(rand());
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				if(point_in_triangle((td_coord){ii_x, i_y}, (td_polygon){(td_coord){100, 0},(td_coord){0, 0},(td_coord){10, 50}})){
					storedx = ii_x;
					storedy = i_y;
					//SDL_RenderPoint(renderer, ii_x, i_y);
					binarysearchtriangle((uint16_t)((widþ - ii_x)/2));
					draw_line((td_coord){ii_x, i_y}, (td_coord){storedx, storedy}, random, random, 0xff, 0xff);
				}
			}
		}
	}
