void autoPlay() {
    unsigned int collidable = 0;
    const int up = 1;
    const int down = 2;
    const int right = 4;
    const int left = 8;
    for(int i = 0; i < (snake_length - 1); i++) {
        if((posX[0] + 1) == posX[i] && posY[0] == posY[i] && sDir!= LEFT)
            collidable |= right;
        if((posX[0] - 1) == posX[i] && posY[0] == posY[i] && sDir != RIGHT)
            collidable |= left;
        if((posY[0] + 1) == posY[i] && posX[0] == posX[i] && sDir != DOWN)
            collidable |= up;
        if((posY[0] - 1) == posY[i] && posX[0] == posX[i] && sDir != UP)
            collidable |= down;
    }
    switch (collidable) {
        case 0: //no collision possible
            moveSnakeOnNoSelfCollision();
            break;
        case 1: //collision on sDir = up
            if (sDir == UP) {
                if (posY[0] != (gridY - 2))
                    turnRight();
                else if (posY[0] != 1)
                    turnLeft();
            }
            break;
        case 2: //collision on sDir = down
            if (sDir == DOWN) {
                if (posY[0] != (gridY - 2))
                    turnRight();
                else if (posY[0] != 1)
                    turnLeft();
            }
            break;
        case 3: //collision on y-axis
            if (sDir == UP || sDir == DOWN) {
                if (posY[0] != (gridY - 2))
                    turnRight();
                else if (posY[0] != 1)
                    turnLeft();
            }
            break;
        case 4: //collision on sDir = right
            if (sDir == RIGHT) {
                if (posX[0] != 1)
                    turnDown();
                else if (posX[0] != (gridX - 2))
                    turnUp();
            }
            break;
        case 5: //collision on sDir = right and/or sDir = up
            if (sDir == RIGHT) {
                if (posX[0] != 1)
                    turnDown();
            }
            else if (sDir == UP) {
                if (posY[0] != 1)
                    turnLeft();
            }
            break;
        case 6: //collision on sDir = right and/or sDir = down
            if (sDir == RIGHT) {
                if (posX[0] != (gridX - 2))
                    turnUp();
            }
            else if (sDir == DOWN) {
                if (posY[0] != 1)
                    turnLeft();
            }
            break;
        case 7: //collision not possible on sDir = left
            if (sDir == UP || sDir == DOWN) {
                if (posY[0] != 1)
                    turnLeft();
            }
            else if (sDir == RIGHT) {
                printf("Trapped\n");
            }
            break;
        case 8: //collision on sDir = left
            if (sDir == LEFT) {
                if (posX[0] != 1)
                    turnDown();
                else if (posX[0] != (gridX - 2))
                    turnUp();
            }
            break;
        case 9: //collision on sDir = left and/or sDir = up
            if (sDir == LEFT) {
                if (posX[0] != 1)
                    turnDown();
            }
            else if (sDir == UP) {
                if (posY[0] != (gridY - 2))
                    turnRight();
            }
            break;
        case 10: //collision on sDir = left and/or sDir = down
            if (sDir == LEFT) {
                if (posX[0] != (gridX - 2))
                    turnUp();
            }
            else if (sDir == DOWN) {
                if (posY[0] != (gridY - 2))
                    turnRight();
            }
            break;
        case 11: //collision not possible on sDir = right
            if (sDir == UP || sDir == DOWN) {
                if (posY[0] != (gridY - 2))
                    turnRight();
            }
            else if (sDir == LEFT) {
                printf("Trapped\n");
            }
            break;
        case 12: //collision on x-axis
            if (sDir == RIGHT || sDir == LEFT) {
                if (posX[0] != 1)
                    turnDown();
                else if (posX[0] != (gridX - 2))
                    turnUp();
            }
            break;
        case 13: //collision not possible on sDir = down
            if (sDir == RIGHT || sDir == LEFT) {
                if (posX[0] != 1)
                    turnDown();
            }
            else if (sDir == UP) {
                printf("Trapped\n");
            }
            break;
        case 14: //collision not possible on sDir = up
            if (sDir == RIGHT || sDir == LEFT) {
                if (posX[0] != (gridX - 2))
                    turnUp();
            }
            else if (sDir == DOWN) {
                printf("Trapped\n");
            }
            break;
        case 15: //collision avoidance not possible - ignore
            printf("Cornered\n");
            break;
    }
}