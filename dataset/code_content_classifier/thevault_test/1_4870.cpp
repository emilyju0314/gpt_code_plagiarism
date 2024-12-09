Vector3 HeightFieldShape::getVertexAt(int x, int y) const {

    // Get the height value
    const decimal height = getHeightAt(x, y);

    // Height values origin
    const decimal heightOrigin = -(mMaxHeight - mMinHeight) * decimal(0.5) - mMinHeight;

    Vector3 vertex;
    switch (mUpAxis) {
        case 0: vertex = Vector3(heightOrigin + height, -mWidth * decimal(0.5) + x, -mLength * decimal(0.5) + y);
                break;
        case 1: vertex = Vector3(-mWidth * decimal(0.5) + x, heightOrigin + height, -mLength * decimal(0.5) + y);
                break;
        case 2: vertex = Vector3(-mWidth * decimal(0.5) + x, -mLength * decimal(0.5) + y, heightOrigin + height);
                break;
        default: assert(false);
    }

    assert(mAABB.contains(vertex));

    return vertex * mScale;
}