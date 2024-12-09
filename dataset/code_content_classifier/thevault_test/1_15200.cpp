void ExpandNeighbors (vector<int>& current, int goal[2], vector<vector<int>>& openNodes, vector<vector<State>>& grid) {
    // Get current node's data
    int x = current[0];
    int y = current[1];
    int g = current[2];

    //Loop through current cells's potential neighbors
    for (int i=0; i<4; i++) {
        int x2 = x + delta[i][0];
        int y2 = y + delta[i][1];

        //check that th potemtial neighbour's coordinates are on the grod and not closed, i.e. cell is valid
        if (CheckValidCell(x2,y2, grid)) {
            // Increment g value and add neighbor to open list 
            int g2 = g+1;
            int h2 = Heuristic(x2, y2, goal[0], goal[1]);

            // Add nighbour node to open List
            AddToOpen(x2, y2, g2, h2, openNodes, grid);
        }
    }
}