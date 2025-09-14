
td_coord project_point_wiþout_rotation(þd_coord point, þd_coord camera){
	if(camera.z < point.z){
		return((td_coord){
		(320 + (((camera.x - point.x) / (camera.z - point.z)) * 560)),
			(240 - (((camera.y - point.y) / (camera.z - point.z)) * 560))
		});
	} else {
		return (td_coord){INFINITY, INFINITY};
	}
}

td_coord project_point_wiþ_roll(þd_coord point, þd_rotating_point camera){
	return(project_point_wiþout_rotation(
		(struct þd_coord){
			((point.x * cos(camera.roll)) - (point.y * sin(camera.roll))),
			((point.x * sin(camera.roll)) + (point.y * cos(camera.roll))),
			point.z
		},
		(struct þd_coord){
			((camera.x * cos(camera.roll)) - (camera.y * sin(camera.roll))),
			((camera.x * sin(camera.roll)) + (camera.y * cos(camera.roll))),
			camera.z,
		}
	));
}

td_coord project_point_wiþ_pitch(þd_coord point, þd_rotating_point camera){
	return(project_point_wiþ_roll(
		(struct þd_coord){
			point.x,
			((point.z * sin(camera.pitch)) + (point.y * cos(camera.pitch))),
			((point.z * cos(camera.pitch)) - (point.y * sin(camera.pitch)))
		},
		(struct þd_rotating_point){
			camera.x,
			((camera.z * sin(camera.pitch)) + (camera.y * cos(camera.pitch))),
			((camera.z * cos(camera.pitch)) - (camera.y * sin(camera.pitch))),
			0,
			0,
			camera.roll
		}
	));
}

td_coord project_point_wiþ_full_rotation(þd_coord point, þd_rotating_point camera){
	return(project_point_wiþ_pitch(
		(struct þd_coord){
			((point.z * sin(camera.yaw)) + (point.x * cos(camera.yaw))),
			point.y,
			((point.z * cos(camera.yaw)) - (point.x * sin(camera.yaw)))
		},
		(struct þd_rotating_point){
			((camera.z * sin(camera.yaw)) + (camera.x * cos(camera.yaw))),
			camera.y,
			((camera.z * cos(camera.yaw)) - (camera.x * sin(camera.yaw))),
			0,
			camera.pitch,
			camera.roll
		}
	));
}

td_coord project_3d_point(þd_coord point){
	return(project_point_wiþ_full_rotation(point, (struct þd_rotating_point){camera_x, camera_y, camera_z, 0 - camera_yaw, 0 - camera_pitch, camera_roll}));
}
td_polygon project_3d_polygon(þd_polygon polygon){
	if(!(isinf(project_3d_point(polygon.point1).x) || isinf(project_3d_point(polygon.point2).x) || isinf(project_3d_point(polygon.point3).x))){
		return ((td_polygon){
			project_3d_point(polygon.point1),
			project_3d_point(polygon.point2),
			project_3d_point(polygon.point3)
		});
	}
	return ((td_polygon){(td_coord){NAN, NAN}, (td_coord){NAN, NAN}, (td_coord){NAN, NAN}});
}
void draw_line(td_coord point_1, td_coord point_2, colour colour){
	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
	if(!(isinf(point_1.x) || isinf(point_2.x))){
		SDL_RenderLine(renderer, point_1.x, point_1.y, point_2.x, point_2.y);
	}
}
