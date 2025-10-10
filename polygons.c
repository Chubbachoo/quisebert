
	/*void drawpoly (þd_coord point1, þd_coord point2, þd_coord point3){
		draw3dline(point1, point2);
		draw3dline(point2, point3);
		draw3dline(point1, point3);
	}*/
	void drawwireframequad (þd_coord point1, þd_coord point2, þd_coord point3, þd_coord point4, colour colour){
		draw3dline(point1, point2, colour);
		draw3dline(point1, point3, colour);
		draw3dline(point1, point4, colour);
		draw3dline(point2, point3, colour);
		draw3dline(point2, point4, colour);
		draw3dline(point3, point4, colour);
	}
	void drawcube(þd_coord point1, þd_coord point2, colour colour){
		td_coord vert000 = project_3d_point((þd_coord){point1.x, point1.y, point1.z});
		td_coord vert100 = project_3d_point((þd_coord){point2.x, point1.y, point1.z});
		td_coord vert010 = project_3d_point((þd_coord){point1.x, point2.y, point1.z});
		td_coord vert110 = project_3d_point((þd_coord){point2.x, point2.y, point1.z});
		td_coord vert001 = project_3d_point((þd_coord){point1.x, point1.y, point2.z});
		td_coord vert101 = project_3d_point((þd_coord){point2.x, point1.y, point2.z});
		td_coord vert011 = project_3d_point((þd_coord){point1.x, point2.y, point2.z});
		td_coord vert111 = project_3d_point((þd_coord){point2.x, point2.y, point2.z});
		
		draw_line(vert000, vert100, colour);//bottom face
		draw_line(vert000, vert001, colour);
		draw_line(vert100, vert101, colour);
		draw_line(vert001, vert101, colour);
		
		draw_line(vert010, vert110, colour);//top face
		draw_line(vert010, vert011, colour);
		draw_line(vert110, vert111, colour);
		draw_line(vert011, vert111, colour);
		
		draw_line(vert000, vert010, colour);//sides
		draw_line(vert100, vert110, colour);
		draw_line(vert001, vert011, colour);
		draw_line(vert101, vert111, colour);
	}
