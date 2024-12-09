void TriangleShape::computeSmoothMeshContact(Vector3 localContactPointTriangle, const Transform& triangleShapeToWorldTransform,
                                             const Transform& worldToOtherShapeTransform, decimal penetrationDepth, bool isTriangleShape1,
                                             Vector3& outNewLocalContactPointOtherShape, Vector3& outSmoothWorldContactTriangleNormal) const {

    // Get the smooth contact normal of the mesh at the contact point on the triangle
    Vector3 triangleLocalNormal = computeSmoothLocalContactNormalForTriangle(localContactPointTriangle);

    // Convert the local contact normal into world-space
    Vector3 triangleWorldNormal = triangleShapeToWorldTransform.getOrientation() * triangleLocalNormal;

    // Penetration axis with direction from triangle to other shape
    Vector3 triangleToOtherShapePenAxis = isTriangleShape1 ? outSmoothWorldContactTriangleNormal : -outSmoothWorldContactTriangleNormal;

    // The triangle normal should be the one in the direction out of the current colliding face of the triangle
    if (triangleWorldNormal.dot(triangleToOtherShapePenAxis) < decimal(0.0)) {
        triangleWorldNormal = -triangleWorldNormal;
        triangleLocalNormal = -triangleLocalNormal;
    }

    // Compute the final contact normal from shape 1 to shape 2
    outSmoothWorldContactTriangleNormal = isTriangleShape1 ? triangleWorldNormal : -triangleWorldNormal;

    // Re-align the local contact point on the other shape such that it is aligned along the new contact normal
    Vector3 otherShapePointTriangleSpace = localContactPointTriangle - triangleLocalNormal * penetrationDepth;
    Vector3 otherShapePoint = worldToOtherShapeTransform * triangleShapeToWorldTransform * otherShapePointTriangleSpace;
    outNewLocalContactPointOtherShape.setAllValues(otherShapePoint.x, otherShapePoint.y, otherShapePoint.z);
}