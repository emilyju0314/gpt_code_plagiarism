inline void dirichletCC::imposeBC() {
    if (rankFlag) {
        dField.F(dField.fWalls(wallNum)) = fieldValue;
    }
}