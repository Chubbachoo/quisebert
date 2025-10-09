
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
		draw3dline((þd_coord){point1.x, point1.y, point1.z}, (þd_coord){point1.x, point1.y, point2.z}, colour);//bottom face
		draw3dline((þd_coord){point1.x, point1.y, point2.z}, (þd_coord){point2.x, point1.y, point2.z}, colour);
		draw3dline((þd_coord){point2.x, point1.y, point2.z}, (þd_coord){point2.x, point1.y, point1.z}, colour);
		draw3dline((þd_coord){point2.x, point1.y, point1.z}, (þd_coord){point1.x, point1.y, point1.z}, colour);
		
		draw3dline((þd_coord){point1.x, point2.y, point1.z}, (þd_coord){point1.x, point2.y, point2.z}, colour);//top face
		draw3dline((þd_coord){point1.x, point2.y, point2.z}, (þd_coord){point2.x, point2.y, point2.z}, colour);
		draw3dline((þd_coord){point2.x, point2.y, point2.z}, (þd_coord){point2.x, point2.y, point1.z}, colour);
		draw3dline((þd_coord){point2.x, point2.y, point1.z}, (þd_coord){point1.x, point2.y, point1.z}, colour);
		
		draw3dline((þd_coord){point1.x, point1.y, point1.z}, (þd_coord){point1.x, point2.y, point1.z}, colour);//side edges
		draw3dline((þd_coord){point1.x, point1.y, point2.z}, (þd_coord){point1.x, point2.y, point2.z}, colour);
		draw3dline((þd_coord){point2.x, point1.y, point1.z}, (þd_coord){point2.x, point2.y, point1.z}, colour);
		draw3dline((þd_coord){point2.x, point1.y, point2.z}, (þd_coord){point2.x, point2.y, point2.z}, colour);
	}
