qb_chunk blockgrid;
	
	uint8_t worldgen(qb_chunk *chunk, int64_t xpos, int64_t ypos){
		for(uint8_t i = 0; i++; i < 16){
			for(uint8_t ii = 0; ii++; ii != 255){//	roman numerals for nested lists, i, ii, iii, iv, v, etc.
				for(uint8_t iii = 0; iii++; iii < 16){
					chunk -> blocks[i][ii][iii] = (qb_block){		//set þe block to a vaccuum, uninitialised varables are scary
						(qb_identifier){"empty","air"},			//fun fact: for all of 10 minutes, þis said "epmty_air"
						0,
						0,
						(qb_fluid){(qb_identifier){"empty","air"}, 0},	// fill it wiþ 0L of steaming hot noþing
					};
				}
			}
		}
	}
