bool HeightFieldShape::computeEnteringRayGridCoordinates(const Ray& ray, int& i, int& j, Vector3& outHitGridPoint) const {
    
    decimal stepI, stepJ;
    const Vector3 aabbSize = mAABB.getExtent();

    assert(mNbColumns > 0);
    assert(mNbRows > 0);

    const int nbCellsI = mNbColumns - 1;
    const int nbCellsJ = mNbRows - 1;

    if (mAABB.raycast(ray, outHitGridPoint)) {

        // Map the hit point into the grid range [0, mNbColumns - 1], [0, mNbRows - 1]
        outHitGridPoint -= mAABB.getMin();

        switch(mUpAxis) {
            case 0 : stepI = aabbSize.y / nbCellsI;
                     stepJ = aabbSize.z / nbCellsJ;
                     i = clamp(int(outHitGridPoint.y / stepI), 0, nbCellsI - 1);
                     j = clamp(int(outHitGridPoint.z / stepJ), 0, nbCellsJ - 1);
                     break;
            case 1 : stepI = aabbSize.x / nbCellsI;
                     stepJ = aabbSize.z / nbCellsJ;
                     i = clamp(int(outHitGridPoint.x / stepI), 0, nbCellsI - 1);
                     j = clamp(int(outHitGridPoint.z / stepJ), 0, nbCellsJ - 1);
                     break;
            case 2 : stepI = aabbSize.x / nbCellsI;
                     stepJ = aabbSize.y / nbCellsJ;
                     i = clamp(int(outHitGridPoint.x / stepI), 0, nbCellsI - 1);
                     j = clamp(int(outHitGridPoint.y / stepJ), 0, nbCellsJ - 1);
                     break;
        }

        assert(i >= 0 && i < nbCellsI);
        assert(j >= 0 && j < nbCellsJ);
        return true;
    }
    
    return false;
}