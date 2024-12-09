void AddToOpen(int x, int y, int g, int h, std::vector<std::vector<int>>& openNodes, std::vector<std::vector<State>>& grid) {
    
    // Create a vector node in the form (x,y,g,h) and push vector node to open list
    openNodes.push_back(std::vector<int> {x, y, g, h});
    // Set grid value for (x,y) as blocked
    grid[x][y] = State::kClosed;
}