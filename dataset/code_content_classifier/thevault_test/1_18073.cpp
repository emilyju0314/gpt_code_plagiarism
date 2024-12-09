void Game1010::restart() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        state.board[i] = false;
    }
    state.tile = rand() % NUM_TILES; // generate random number between 0 and NUM_TILES-1
    
    // reset the score
    score = 0;
}