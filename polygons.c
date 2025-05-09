
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
	void drawcube(þd_coord point1, þd_coord point2){
		drawwireframequad(
			(þd_coord){point1.x, point1.y, point1.z},
			(þd_coord){point2.x, point1.y, point1.z},
			(þd_coord){point1.x, point1.y, point2.z},
			(þd_coord){point2.x, point1.y, point2.z}
		); //bottom face (assuming point1 is lowest)
		drawwireframequad(
			(þd_coord){point1.x, point2.y, point1.z},
			(þd_coord){point2.x, point2.y, point1.z},
			(þd_coord){point1.x, point2.y, point2.z},
			(þd_coord){point2.x, point2.y, point2.z}
		);
		drawwireframequad(
			(þd_coord){point1.x, point1.y, point1.z},
			(þd_coord){point2.x, point1.y, point1.z},
			(þd_coord){point1.x, point2.y, point1.z},
			(þd_coord){point2.x, point2.y, point1.z}
		);
		drawwireframequad(
			(þd_coord){point1.x, point1.y, point2.z},
			(þd_coord){point2.x, point1.y, point2.z},
			(þd_coord){point1.x, point2.y, point2.z},
			(þd_coord){point2.x, point2.y, point2.z}
		);
		drawwireframequad(
			(þd_coord){point1.x, point1.y, point1.z},
			(þd_coord){point1.x, point1.y, point2.z},
			(þd_coord){point1.x, point2.y, point1.z},
			(þd_coord){point1.x, point2.y, point2.z}
		);
		drawwireframequad(
			(þd_coord){point2.x, point1.y, point1.z},
			(þd_coord){point2.x, point1.y, point2.z},
			(þd_coord){point2.x, point2.y, point1.z},
			(þd_coord){point2.x, point2.y, point2.z}
		);
	}
