
	void drawpoly (þd_coord point1, þd_coord point2, þd_coord point3){
		draw3dline(point1, point2);
		draw3dline(point2, point3);
		draw3dline(point1, point3);
	}
	void drawwireframequad (þd_coord point1, þd_coord point2, þd_coord point3, þd_coord point4){
		draw3dline(point1, point2);
		draw3dline(point1, point3);
		draw3dline(point1, point4);
		draw3dline(point2, point3);
		draw3dline(point2, point4);
		draw3dline(point3, point4);
	}
