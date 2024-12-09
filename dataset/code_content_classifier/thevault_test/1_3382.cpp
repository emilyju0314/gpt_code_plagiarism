void drawGrid() {
    if(gridFlag) {
        for (int x = 0; x < gridX; x++) {
            for (int y = 0; y < gridY; y++) {
                if (!gamePause && !gameOver && !(x == 0 || x == gridX - 1 || y == 0 || y == gridY - 1))
                    drawCell(x, y, 1.0, GREY);
            }
        }
    }
}