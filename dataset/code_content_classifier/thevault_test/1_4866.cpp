void HeightFieldShape::computeMinMaxGridCoordinates(int* minCoords, int* maxCoords, const AABB& aabbToCollide) const {

    // Clamp the min/max coords of the AABB to collide inside the height field AABB
    Vector3 minPoint = Vector3::max(aabbToCollide.getMin(), mAABB.getMin());
    minPoint = Vector3::min(minPoint, mAABB.getMax());

    Vector3 maxPoint = Vector3::min(aabbToCollide.getMax(), mAABB.getMax());
    maxPoint = Vector3::max(maxPoint, mAABB.getMin());

    // Translate the min/max points such that the we compute grid points from [0 ... mNbWidthGridPoints]
    // and from [0 ... mNbLengthGridPoints] because the AABB coordinates range are [-mWdith/2 ... mWidth/2]
    // and [-mLength/2 ... mLength/2]
    const Vector3 translateVec = mAABB.getExtent() * decimal(0.5);
    minPoint += translateVec;
    maxPoint += translateVec;

    assert(minPoint.x >= 0);
    assert(minPoint.y >= 0);
    assert(minPoint.z >= 0);
    assert(maxPoint.x >= 0);
    assert(maxPoint.y >= 0);
    assert(maxPoint.z >= 0);

    // Convert the floating min/max coords of the AABB into closest integer
    // grid values (note that we use the closest grid coordinate that is out
    // of the AABB)
    minCoords[0] = static_cast<int>(minPoint.x + 0.5) - 1;
    minCoords[1] = static_cast<int>(minPoint.y + 0.5) - 1;
    minCoords[2] = static_cast<int>(minPoint.z + 0.5) - 1;

    maxCoords[0] = static_cast<int>(maxPoint.x + 0.5) + 1;
    maxCoords[1] = static_cast<int>(maxPoint.y + 0.5) + 1;
    maxCoords[2] = static_cast<int>(maxPoint.z + 0.5) + 1;
}