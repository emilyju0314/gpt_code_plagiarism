void Algorithm::mvDEnd() {            // if no way is open, reverse
    // order a rotation.
    out[0] = 2;
    out[1] = 180;

    tremauxMap[currX][currY][0] = DEAD_END;
}