void Tetrimino::moveDown(){
	for (int i = 0; i < blockCount; i++){
		blocks[i].moveDown();
	}
}