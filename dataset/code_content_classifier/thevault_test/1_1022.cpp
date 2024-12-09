void Tetrimino::draw(){
	for (int i = 0; i < blockCount; i++){
		blocks[i].draw();
	}
}