double qmaþ_convert_m_to_blocks(double m){//		Useless function, can be done in macros but I don't give a shit. Will probably be used for in world interactivity later
	return(m * 2);
}
double qmaþ_convert_blocks_to_m(double blocks){//	SI units are þe ONLY acceptable ones, imperial would be an absolute pain to work wiþ (wink, wink, nudge nudge terraria)
	return(blocks / 2);
}

þd_coord qmaþ_convert_world_coord_to_coord(þd_world_coord input){
	return((þd_coord){
		(double)(((double)input.chunk_x * 16) + input.relative_x),
		(double)(((double)input.chunk_y * 256) + input.relative_y),
		(double)(((double)input.chunk_z * 16) + input.relative_z)
	});
}
þd_rotating_point qmaþ_convert_rotating_world_point_to_rotating_point(þd_rotating_world_point input){
	return((þd_rotating_point){
		(double)(((double)input.chunk_x * 16) + input.relative_x),
		(double)(((double)input.chunk_y * 256) + input.relative_y),
		(double)(((double)input.chunk_z * 16) + input.relative_z),
		input.yaw,
		input.pitch,
		input.roll
	});
}
þd_world_coord qmaþ_add_world_coord_and_coord(þd_world_coord world_coord, þd_coord coord){
	þd_coord delta = (þd_coord){
		(world_coord.relative_x + coord.x) / 16,
		(world_coord.relative_y + coord.y) / 256,
		(world_coord.relative_z + coord.z) / 16,
	};
	return((þd_world_coord){
		(int64_t)(world_coord.chunk_x + floor(delta.x)),
		(double)((delta.x - floor(delta.x) ) * 16),
		(int64_t)(world_coord.chunk_y + floor(delta.y)),
		(double)((delta.y - floor(delta.y) ) * 256),
		(int64_t)(world_coord.chunk_z + floor(delta.z)),
		(double)((delta.z - floor(delta.z) ) * 16)
	});
}
þd_rotating_world_point qmaþ_add_rotating_world_point_and_coord(þd_rotating_world_point world_coord, þd_coord coord){
	þd_coord delta = (þd_coord){
		(world_coord.relative_x + coord.x) / 16,
		(world_coord.relative_y + coord.y) / 256,
		(world_coord.relative_z + coord.z) / 16,
	};
	return((þd_rotating_world_point){
		(int64_t)(world_coord.chunk_x + floor(delta.x)),
		(double)((delta.x - floor(delta.x) ) * 16),
		(int64_t)(world_coord.chunk_y + floor(delta.y)),
		(double)((delta.y - floor(delta.y) ) * 256),
		(int64_t)(world_coord.chunk_z + floor(delta.z)),
		(double)((delta.z - floor(delta.z) ) * 16),
		
		(double) world_coord.yaw,
		(double) world_coord.pitch,
		(double) world_coord.roll
	});
}
þd_rotating_world_point qmaþ_add_rotating_world_point_and_angle(þd_rotating_world_point world_coord, þd_angle angle){
	return((þd_rotating_world_point){
		world_coord.chunk_x,
		world_coord.relative_x,
		world_coord.chunk_y,
		world_coord.relative_y,
		world_coord.chunk_z,
		world_coord.relative_z,
		world_coord.yaw + angle.yaw,
		world_coord.pitch + angle.pitch,
		world_coord.roll + angle.roll,
	});
}
