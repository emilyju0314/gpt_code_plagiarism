uint8_t Graphics::mget(int celx, int cely){
	if (cely < 32) {
		return _memory->mapData[cely * 128 + celx];
	}
	else if (cely < 64){
		return _memory->spriteSheetData[cely* 128 + celx];
	}

	return 0;
}