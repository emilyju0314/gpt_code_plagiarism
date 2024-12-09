void ZTetrimino::rotate(){
	switch (orientation){
	case TOP_FACING_TOP:
	case TOP_FACING_BOTTOM:
		blocks[0].moveRight();
		blocks[0].moveUp();
		blocks[2].moveLeft();
		blocks[2].moveUp();
		blocks[3].moveLeft();
		blocks[3].moveLeft();
		orientation = TOP_FACING_RIGHT;
		break;
	case TOP_FACING_RIGHT:
	case TOP_FACING_LEFT:
		blocks[0].moveLeft();
		blocks[0].moveDown();
		blocks[2].moveRight();
		blocks[2].moveDown();
		blocks[3].moveRight();
		blocks[3].moveRight();
		orientation = TOP_FACING_BOTTOM;
		break;
	default:
		break;
	}
}