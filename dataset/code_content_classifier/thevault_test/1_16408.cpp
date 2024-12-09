static void TransformDimensions(const SkMatrix& matrix, float srcWidth, float srcHeight, float* destWidth, float* destHeight) {
    // Transform 3 points to see how long each side of the bitmap will be.
    SkPoint src_points[3];  // (0, 0), (width, 0), (0, height).
    src_points[0].set(0, 0);
    src_points[1].set(SkFloatToScalar(srcWidth), 0);
    src_points[2].set(0, SkFloatToScalar(srcHeight));

    // Now measure the length of the two transformed vectors relative to the
    // transformed origin to see how big the bitmap will be. Note: for skews,
    // this isn't the best thing, but we don't have skews.
    SkPoint dest_points[3];
    matrix.mapPoints(dest_points, src_points, 3);
    *destWidth = SkScalarToFloat((dest_points[1] - dest_points[0]).length());
    *destHeight = SkScalarToFloat((dest_points[2] - dest_points[0]).length());
}