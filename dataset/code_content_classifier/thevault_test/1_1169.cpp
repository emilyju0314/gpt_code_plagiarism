int* Board::window_size(){
	int *size = new int[2];

	//The score section needs 3 columns and title uses 1 puyo height (Block)
	size[0] = (MARGIN * 2) + (PUYO_WIDTH * (cols + 3));
	size[1] = (MARGIN * 2) + (PUYO_HEIGHT * (rows + 1) + PUYO_HEIGHT);

	return size;
}