void Grid::clearGrid() {
    for (int i = 0; i < sizeX+2*(hide+1); i++) {
        for (int j = 0; j < sizeY+2*(hide+1); j++) {
            setState(i, j, 0);
        }
    }
}