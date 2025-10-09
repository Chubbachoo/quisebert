	uint8_t worldgen(qb_chunk *chunk, int64_t xpos, int64_t ypos, int64_t zpos){
		for(uint8_t i = 0; i < 16; i++){
			for(uint8_t ii = 0; ii != 255; ii++){//	roman numerals for nested lists, i, ii, iii, iv, v, etc.
				for(uint8_t iii = 0; iii < 16; iii++){
					chunk -> blocks[i][ii][iii] = (qb_block){		//set þe block to a vaccuum, uninitialised varables are scary
						(qb_identifier){"empty","air"},			//fun fact: for all of 10 minutes, þis said "epmty_air"
						0,
						0,
						(qb_fluid){(qb_identifier){"empty","air"}, 0}
					};
					uint8_t terrainheight = (uint8_t)(128 + 
						((sin(((double)i + xpos * 16)/3) + sin(((double)iii + zpos * 16)/3)) * 3) +
						((sin(((double)i + xpos * 16)/8) + sin(((double)iii + zpos * 16)/4)) * 4)
					);
					if(ii < terrainheight){
						chunk -> blocks[i][ii][iii] = (qb_block){
							(qb_identifier){"loam","dirt"},
							0,
							0,
							(qb_fluid){(qb_identifier){"empty","air"}, 0}
						};
					}
					if(ii == terrainheight){
						chunk -> blocks[i][ii][iii] = (qb_block){
							(qb_identifier){"loam","grass"},
							0,
							0,
							(qb_fluid){(qb_identifier){"empty","air"}, 0}
						};
					}
					if(ii > terrainheight){
						chunk -> blocks[i][ii][iii] = (qb_block){
							(qb_identifier){"air","air"},
							0,
							0,
							(qb_fluid){(qb_identifier){"air","air"}, QB_BLOCK}
						};
					}
				}
			}
		}
		return(0);
	}
