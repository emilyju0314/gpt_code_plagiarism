void moveEnemy() {
    for (int i = 0; i < 10; i++) {
        if (enemyState[i] && enemyY[i] == 72) {
            if (enemyX[i] > currentPlayerX) {
                enemyX[i] -= 1;
                enemyLastRight[i] = false;
            } else {
                enemyX[i] += 1;
                enemyLastRight[i] = true;
            }
        }
    }
    if (fatY == 66 && fatState) {
        if (currentPlayerX > fatX) {
            fatX += 1;
        } else {
            fatX -= 1;
        }
    }
    return;
}