
void draw_3d_line_wiþout_rotation(þd_coord point_1, þd_coord point_2, þd_coord camera){
	if (camera.z < point_1.z && camera.z < point_2.z) {
		draw_segmented_line(4, point_1, point_2, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, camera);
		SDL_RenderLine(renderer, 
		(320 + (((camera.x - point_1.x) / (camera.z - point_1.z)) * 560)), 
		(240 - (((camera.y - point_1.y) / (camera.z - point_1.z)) * 560)), 
		(320 + (((camera.x - point_2.x) / (camera.z - point_2.z)) * 560)), 
		(240 - (((camera.y - point_2.y) / (camera.z - point_2.z)) * 560)));
	}
}

void draw_3d_line_wiþ_roll(þd_coord point_1, þd_coord point_2, þd_rotating_point camera){
	draw_3d_line_wiþout_rotation(
		(struct þd_coord){
			((point_1.x * cos(camera.roll)) - (point_1.y * sin(camera.roll))),
			((point_1.x * sin(camera.roll)) + (point_1.y * cos(camera.roll))),
			point_1.z
		},
		(struct þd_coord){
			((point_2.x * cos(camera.roll)) - (point_2.y * sin(camera.roll))),
			((point_2.x * sin(camera.roll)) + (point_2.y * cos(camera.roll))),
			point_2.z
		},
		(struct þd_coord){
			((camera.x * cos(camera.roll)) - (camera.y * sin(camera.roll))),
			((camera.x * sin(camera.roll)) + (camera.y * cos(camera.roll))),
			camera.z,
		}
	);
}

void draw_3d_line_wiþ_pitch(þd_coord point_1, þd_coord point_2, þd_rotating_point camera){
	draw_3d_line_wiþ_roll(
		(struct þd_coord){
			point_1.x,
			((point_1.z * sin(camera.pitch)) + (point_1.y * cos(camera.pitch))),
			((point_1.z * cos(camera.pitch)) - (point_1.y * sin(camera.pitch)))
		},
		(struct þd_coord){
			point_2.x,
			((point_2.z * sin(camera.pitch)) + (point_2.y * cos(camera.pitch))),
			((point_2.z * cos(camera.pitch)) - (point_2.y * sin(camera.pitch)))
		},
		(struct þd_rotating_point){
			camera.x,
			((camera.z * sin(camera.pitch)) + (camera.y * cos(camera.pitch))),
			((camera.z * cos(camera.pitch)) - (camera.y * sin(camera.pitch))),
			0,
			0,
			camera.roll
		}
	);
}

void draw_3d_line_wiþ_full_rotation(þd_coord point_1, þd_coord point_2, þd_rotating_point camera){
	draw_3d_line_wiþ_pitch(
		(struct þd_coord){
			((point_1.z * sin(camera.yaw)) + (point_1.x * cos(camera.yaw))),
			point_1.y,
			((point_1.z * cos(camera.yaw)) - (point_1.x * sin(camera.yaw)))
		},
		(struct þd_coord){
			((point_2.z * sin(camera.yaw)) + (point_2.x * cos(camera.yaw))),
			point_2.y,
			((point_2.z * cos(camera.yaw)) - (point_2.x * sin(camera.yaw)))
		},
		(struct þd_rotating_point){
			((camera.z * sin(camera.yaw)) + (camera.x * cos(camera.yaw))),
			camera.y,
			((camera.z * cos(camera.yaw)) - (camera.x * sin(camera.yaw))),
			0,
			camera.pitch,
			camera.roll
		}
	);
}

void draw3dline(þd_coord point_1, þd_coord point_2){
	draw_3d_line_wiþ_full_rotation(point_1, point_2, (struct þd_rotating_point){camera_x, camera_y, camera_z, 0 - camera_yaw, 0 - camera_pitch, camera_roll});
}
