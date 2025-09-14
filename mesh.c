þd_polygon mesh_data[1024];
colour mesh_colour[1024];
uint16_t meshlengþ = 0;

uint8_t add_triangle_to_mesh(þd_polygon polygon, colour polygon_colour){
	if (meshlengþ >= 1024){
		//printf("Error: mesh buffer overflow.");
		return 1;
	}
	mesh_data[meshlengþ] = polygon;
	mesh_colour[meshlengþ] = polygon_colour;
	meshlengþ += 1;
	return 0;
}
