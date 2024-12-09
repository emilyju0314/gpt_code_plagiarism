void Game1010::act(int action) {
    // get the next state
    ActionOutput ao = getAfterState(action, state);
    if (ao.valid) {
        state = getNextState(ao.afterstate);
        
        // add the score with the reward
        score += ao.reward;
    }
}