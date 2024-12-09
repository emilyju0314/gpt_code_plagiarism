bool Game1010::isTerminated(State inputstate) {
    // extract the tile information
    const int* tile = &tiles[tilesSizeCumSum[inputstate.tile]];
    int tileSize = tilesSize[inputstate.tile];
    int tileWidth = tilesWidth[inputstate.tile];
    
    int hspace = SIZE-tilesHeight[inputstate.tile];
    int wspace = SIZE-tileWidth;
    
    // check all possible actions
    int action = 0;
    bool isValid;
    for (int row = 0; row <= hspace; ++row) {
        for (int col = 0; col <= wspace; ++col) {
            
            // for a certain action, check if the tiles are blank
            isValid = true;
            for (int i = 0; i < tileSize; ++i) {
                if (inputstate.board[tile[i]+action]) {
                    isValid = false;
                    break;
                }
            }
            
            // if the action is valid, then it is not terminated
            if (isValid) return false;
            action++;
        }
        action += tileWidth - 1;
    }
    return true;
}