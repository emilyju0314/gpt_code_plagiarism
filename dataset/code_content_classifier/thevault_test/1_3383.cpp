void moveSnakeOnNoSelfCollision() {
    int xdiff = foodX - posX[0]; //distance between snake and food on xaxis
    int ydiff = foodY - posY[0]; //distance between snake and food on yaxis
    if (abs(xdiff) >= abs(ydiff)) {
        if (xdiff >= 0) {
            if (sDir != LEFT)
                turnRight();
            else {
                if (posX[0] != 1 || posY[0] != (gridY - 2))
                    turnUp();
                else if (posX[0] != (gridX - 2) || posY[0] != 1)
                    turnDown();
            }
        }
        else if (xdiff < 0) {
            if (sDir != RIGHT)
                turnLeft();
            else {
                if (posX[0] != 1 || posY[0] != (gridY - 2))
                    turnUp();
                else if (posX[0] != (gridX - 2) || posY[0] != 1)
                    turnDown();
            }
        }
    }
    else {
        if (ydiff >= 0) {
            if (sDir != DOWN)
                turnUp();
            else {
                if (posY[0] != 1 || posX[0] != (gridX - 2))
                    turnRight();
                else if (posY[0] != (gridY - 2) || posX[0] != 1)
                    turnLeft();
            }
        }
        else if (ydiff < 0) {
            if (sDir != UP)
                turnDown();
            else {
                if (posY[0] != 1 || posX[0] != (gridX - 2))
                    turnRight();
                else if (posY[0] != (gridY - 2) || posX[0] != 1)
                    turnLeft();
            }
        }
    }
}