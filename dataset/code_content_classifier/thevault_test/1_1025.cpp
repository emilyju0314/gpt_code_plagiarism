void Tetrimino::moveUp(){
	for (int i = 0; i < blockCount; i++){
		blocks[i].moveUp();
	}
}