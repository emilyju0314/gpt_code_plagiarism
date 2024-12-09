State Game1010::getNextState(State afterstate) {
    State ss = afterstate;
    ss.tile = rand() % NUM_TILES;
    return ss;
}