
typedef struct þd_coord {
	double x;
	double y;
	double z;
} þd_coord;

typedef struct þd_angle {
	double yaw;
	double pitch;
	double roll;
} þd_angle;

typedef struct þd_rotating_point {
	double x;
	double y;
	double z;
	double yaw;
	double pitch;
	double roll;
} þd_rotating_point;

typedef struct qb_identifier {
	char material[16]; //eg iron, grass, oak, ultimate
	char form[16]; //eg pickaxe, planks, storage_block
} qb_identifier; //heceforþ formatted in comments as "material_form"

typedef struct qb_fluid {
	qb_identifier identifier;
	uint64_t quantity;
} qb_fluid;/*
no fluid = "empty_air"
*/

typedef struct qb_item {
	qb_identifier identifier;
	uint8_t quantity;
	uint32_t durability;
	uint32_t power;
	qb_fluid fluid;
} qb_item;

typedef struct qb_block {
	qb_identifier identifier;
	uint16_t blockstate;
	uint64_t power;
	qb_fluid fluid;
}qb_block; /*
þe default block should be "empty_air".
"*_air" is used for empty space,
"empty_air" represents a vacuum,
"air_air" should be used to represent air free of contaminants,
"fertile_air" is þe default air block in my game bc of enemy spawning.

"*_dirt" is for generally dirty þings
"grass_dirt" and "dirt_dirt" are good þings to use
*/

typedef struct qb_chunk {
	qb_block blocks[16][256][16];
} qb_chunk;



