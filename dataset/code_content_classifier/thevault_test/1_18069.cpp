ActionOutput Game1010::getAfterState(int action, State inputstate) {
    // determine the row and column of the action
    #ifdef TIMED_ACT
    clock_t t4 = clock();
    #endif
    int row = action / SIZE;
    int col = action % SIZE;
    
    // extract the tile information
    const int* tile = &tiles[tilesSizeCumSum[inputstate.tile]];
    const int tileSize = tilesSize[inputstate.tile];
    const int tileHeight = tilesHeight[inputstate.tile];
    const int tileWidth = tilesWidth[inputstate.tile];
    
    #ifdef TIMED_ACT
    times[4] += clock() - t4;
    
    clock_t t5 = clock();
    #endif
    // check if the action is valid
    bool isValid = true;
    if ((row < 0) || (col < 0) || (row > SIZE - tileHeight) || (col > SIZE - tileWidth)) { // check if the tiles are inside the box
        isValid = false;
    }
    else {
        // check if all tiles to be placed are blank
        for (int i = 0; i < tileSize; ++i) {
            if (inputstate.board[tile[i]+action]) {
                isValid = false;
                break;
            }
        }
    }
    #ifdef TIMED_ACT
    times[5] += clock() - t5;
    #endif
    
    // if the action is not valid, return the next state as it is
    if (!isValid) {
        ActionOutput ao;
        ao.afterstate = inputstate;
        ao.reward = 0;
        ao.valid = false;
        return ao;
    }
    
    #ifdef TIMED_ACT
    clock_t t6 = clock();
    #endif
    // if it's valid, then place the tiles on the board
    State nextstate = inputstate;
    for (int i = 0; i < tileSize; ++i) {
        nextstate.board[tile[i]+action] = true;
    }
    #ifdef TIMED_ACT
    times[6] += clock() - t6;
    
    clock_t t7 = clock();
    #endif
    // check the completed rows and columns
    bool columnsIncomplete[tileWidth] = {false};
    bool rowsIncomplete[tileHeight] = {false};
    for (int i = 0; i < tileHeight; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (nextstate.board[(i+row)*SIZE+j] == false) {
                rowsIncomplete[i] = true;
                columnsIncomplete[j] = true;
                break;
            }
        }
    }
    for (int j = 0; j < tileWidth; ++j) {
        if (columnsIncomplete[j]) continue;
        for (int i = 0; i < SIZE; ++i) {
            if (nextstate.board[i*SIZE+j+col] == false) {
                columnsIncomplete[j] = true;
                break;
            }
        }
    }
    #ifdef TIMED_ACT
    times[7] += clock() - t7;
    
    clock_t t8 = clock();
    #endif
    // remove the completed rows and columns
    for (int i = 0; i < tileHeight; ++i) {
        if (!rowsIncomplete[i]) { // row is complete
            for (int j = 0; j < SIZE; ++j) {
                nextstate.board[(i+row)*SIZE+j] = false;
            }
        }
    }
    for (int j = 0; j < tileWidth; ++j) {
        if (!columnsIncomplete[j]) { // the column is complete
            for (int i = 0; i < SIZE; ++i) {
                nextstate.board[i*SIZE+j+col] = false;
            }
        }
    }
    #ifdef TIMED_ACT
    times[8] += clock() - t8;
    
    clock_t t9 = clock();
    #endif
    // calculate the number of completed rows and cols
    int ncomplete = 0;
    for (int i = 0; i < tileHeight; ++i) {
        if (!rowsIncomplete[i]) ++ncomplete;
    }
    for (int i = 0; i < tileWidth; ++i) {
        if (!columnsIncomplete[i]) ++ncomplete;
    }
    #ifdef TIMED_ACT
    times[9] += clock() - t9;
    clock_t t10 = clock();
    times[10] += clock() - t10;
    #endif
    
    // calculate the reward
    int reward = tileSize + (ncomplete+1)*ncomplete*5;
    
    // return the output_iterator
    ActionOutput ao;
    ao.afterstate = nextstate;
    ao.reward = reward;
    ao.valid = true;
    return ao;
}