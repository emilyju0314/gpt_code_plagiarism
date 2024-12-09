int Grid::sumNeighbors(int i, int j){
    return state[i-1][j+1] + state[i+1][j+1] +
            state[i-1][j] + state[i+1][j] +
            state[i-1][j-1] + state[i+1][j-1] +
            state[i][j+1] + state[i][j-1];
}