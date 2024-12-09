bool HeightFieldShape::raycast(const Ray& ray, RaycastInfo& raycastInfo, Collider* collider, MemoryAllocator& allocator) const {

    RP3D_PROFILE("HeightFieldShape::raycast()", mProfiler);

    // Apply the concave mesh inverse scale factor because the mesh is stored without scaling
    // inside the dynamic AABB tree
    const Vector3 inverseScale(decimal(1.0) / mScale.x, decimal(1.0) / mScale.y, decimal(1.0) / mScale.z);
    Ray scaledRay(ray.point1 * inverseScale, ray.point2 * inverseScale, ray.maxFraction);

    bool isHit = false;

    // Compute the grid coordinates where the ray is entering the AABB of the height field
    int i, j;
    Vector3 outHitGridPoint;
    if (computeEnteringRayGridCoordinates(scaledRay, i, j, outHitGridPoint)) {

        const int nbCellsI = mNbColumns - 1;
        const int nbCellsJ = mNbRows - 1;

        const Vector3 aabbSize = mAABB.getExtent();

        const Vector3 rayDirection = scaledRay.point2 - scaledRay.point1;

        int stepI, stepJ;
        decimal tMaxI, tMaxJ, nextI, nextJ, tDeltaI, tDeltaJ, sizeI, sizeJ;

        switch(mUpAxis) {
            case 0 : stepI = rayDirection.y > 0 ? 1 : (rayDirection.y < 0 ? -1 : 0);
                     stepJ = rayDirection.z > 0 ? 1 : (rayDirection.z < 0 ? -1 : 0);
                     nextI = static_cast<decimal>(stepI >= 0 ? i + 1 : i);
                     nextJ = static_cast<decimal>(stepJ >= 0 ? j + 1 : j);
                     sizeI = aabbSize.y / nbCellsI;
                     sizeJ = aabbSize.z / nbCellsJ;
                     tMaxI = ((nextI * sizeI) - outHitGridPoint.y) / rayDirection.y;
                     tMaxJ = ((nextJ * sizeJ) - outHitGridPoint.z) / rayDirection.z;
                     tDeltaI = sizeI / std::abs(rayDirection.y);
                     tDeltaJ = sizeJ / std::abs(rayDirection.z);
                     break;
            case 1 : stepI = rayDirection.x > 0 ? 1 : (rayDirection.x < 0 ? -1 : 0);
                     stepJ = rayDirection.z > 0 ? 1 : (rayDirection.z < 0 ? -1 : 0);
                     nextI = static_cast<decimal>(stepI >= 0 ? i + 1 : i);
                     nextJ = static_cast<decimal>(stepJ >= 0 ? j + 1 : j);
                     sizeI = aabbSize.x / nbCellsI;
                     sizeJ = aabbSize.z / nbCellsJ;
                     tMaxI = ((nextI * sizeI) - outHitGridPoint.x) / rayDirection.x;
                     tMaxJ = ((nextJ * sizeJ) - outHitGridPoint.z) / rayDirection.z;
                     tDeltaI = sizeI / std::abs(rayDirection.x);
                     tDeltaJ = sizeJ / std::abs(rayDirection.z);
                     break;
            case 2 : stepI = rayDirection.x > 0 ? 1 : (rayDirection.x < 0 ? -1 : 0);
                     stepJ = rayDirection.y > 0 ? 1 : (rayDirection.y < 0 ? -1 : 0);
                     nextI = static_cast<decimal>(stepI >= 0 ? i + 1 : i);
                     nextJ = static_cast<decimal>(stepJ >= 0 ? j + 1 : j);
                     sizeI = aabbSize.x / nbCellsI;
                     sizeJ = aabbSize.y / nbCellsJ;
                     tMaxI = ((nextI * sizeI) - outHitGridPoint.x) / rayDirection.x;
                     tMaxJ = ((nextJ * sizeJ) - outHitGridPoint.y) / rayDirection.y;
                     tDeltaI = sizeI / std::abs(rayDirection.x);
                     tDeltaJ = sizeJ / std::abs(rayDirection.y);
                     break;
        }

        decimal smallestHitFraction = ray.maxFraction;

        while (i >= 0 && i < nbCellsI && j >= 0 && j < nbCellsJ) {

           // Compute the four point of the current quad
           const Vector3 p1 = getVertexAt(i, j);
           const Vector3 p2 = getVertexAt(i, j + 1);
           const Vector3 p3 = getVertexAt(i + 1, j);
           const Vector3 p4 = getVertexAt(i + 1, j + 1);

           // Raycast against the first triangle of the cell
           uint32 shapeId = computeTriangleShapeId(i, j, 0);
           isHit |= raycastTriangle(ray, p1, p2, p3, shapeId, collider, raycastInfo, smallestHitFraction, allocator);

           // Raycast against the second triangle of the cell
           shapeId = computeTriangleShapeId(i, j, 1);
           isHit |= raycastTriangle(ray, p3, p2, p4, shapeId, collider, raycastInfo, smallestHitFraction, allocator);

           if (stepI == 0 && stepJ == 0) break;

           if (tMaxI < tMaxJ) {
                tMaxI += tDeltaI;
                i += stepI;
            }
            else {
                tMaxJ += tDeltaJ;
                j += stepJ;
            }
        }
    }

    return isHit;
}