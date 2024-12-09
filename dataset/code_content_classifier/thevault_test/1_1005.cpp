void ZTetrimino::setX(int newX){
	x = newX;
	blocks[0].setX(x);
	blocks[1].setX(x+BLOCK_LENGTH);
	blocks[2].setX(x+BLOCK_LENGTH);
	blocks[3].setX(x+2*BLOCK_LENGTH);
}