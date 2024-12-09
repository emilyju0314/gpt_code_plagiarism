void Board::render(){
	update_falling();
	falling_new_block();
	draw_blocks();
}