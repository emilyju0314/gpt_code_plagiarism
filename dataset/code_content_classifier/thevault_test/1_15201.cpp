std::vector<std::vector<State>> Search (std::vector<std::vector<State>> grid, int init[2], int goal[2]) {
    
    // Create the vector of open nodes.
    vector<vector<int>> open {};
    // Initialize the starting node. 
    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic(x, y, goal[0],goal[1]);

    // Use AddToOpen to add the starting node to the open vector.
    AddToOpen(x, y, g, h, open, grid);

    // while open vector is non empty
    while(open.size() > 0) {

        // Sort open list using CellSort, and get the current node
        CellSort(&open);
        auto current = open.back();
        open.pop_back();

        // Get the x and y values from the current node
        x = current[0];
        y = current[1];
        grid[x][y] = State::kPath;

        // Check if agent has reached the goal. If so, return grid
        if (x == goal[0] && y== goal[1]) {
            grid[init[0]][init[1]] = State::kStart;
            grid[goal[0]][goal[1]] = State::kFinish;
            return grid;
        }

        // If we have year reache the goal, we expand search into neighboring cels
        ExpandNeighbors(current, goal, open, grid);

        // Show each step of A* Search
        // PrintBoard(grid);
    }
    // We've run out of new nodes to explore and haven't found a path.
    cout<<"No path found" << '\n';
    return std::vector<std::vector<State>> {};
}