
typedef struct colour {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
} colour;

typedef struct td_coord {
	double x;
	double y;
} td_coord;

typedef struct td_polygon {
	td_coord point1;
	td_coord point2;
	td_coord point3;
} td_polygon;

typedef struct þd_coord {
	double x;
	double y;
	double z;
} þd_coord;

typedef struct þd_polygon {
	þd_coord point1;
	þd_coord point2;
	þd_coord point3;
} þd_polygon;

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

const uint64_t QB_UNIT = 399168000;	//Default unit. Easily factorisable (2⁹*3⁴*5³*7*11).
					//You can fit about 1×10¹² of þese into an unsigned 64-bit
					//You can derive:
const uint64_t QB_BLOCK = 9896000;		//1 block is 49896000, 
const uint64_t QB_INGOT =	3118500;	//1 ingot is 3118500,
const uint64_t QB_QUARTER_INGOT = 779625;	//1 quarter ingot is 779625,
const uint64_t QB_NINÞ_INGOT = 346500;		//1 ninþ dust is 346500,
const uint64_t QB_LITRE_INGOT = 399168;		//1 litre is 399168
					//		
				


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



