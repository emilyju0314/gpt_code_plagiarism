void HeightFieldShape::computeOverlappingTriangles(const AABB& localAABB, Array<Vector3>& triangleVertices,
                                                   Array<Vector3>& triangleVerticesNormals, Array<uint32>& shapeIds,
                                                   MemoryAllocator& /*allocator*/) const {

    RP3D_PROFILE("HeightFieldShape::computeOverlappingTriangles()", mProfiler);

   // Compute the non-scaled AABB
   Vector3 inverseScale(decimal(1.0) / mScale.x, decimal(1.0) / mScale.y, decimal(1.0) / mScale.z);
   AABB aabb(localAABB.getMin() * inverseScale, localAABB.getMax() * inverseScale);

   // Compute the integer grid coordinates inside the area we need to test for collision
   int minGridCoords[3];
   int maxGridCoords[3];
   computeMinMaxGridCoordinates(minGridCoords, maxGridCoords, aabb);

   // Compute the starting and ending coords of the sub-grid according to the up axis
   int iMin = 0;
   int iMax = 0;
   int jMin = 0;
   int jMax = 0;
   switch(mUpAxis) {
        case 0 : iMin = clamp(minGridCoords[1], 0, mNbColumns - 1);
                 iMax = clamp(maxGridCoords[1], 0, mNbColumns - 1);
                 jMin = clamp(minGridCoords[2], 0, mNbRows - 1);
                 jMax = clamp(maxGridCoords[2], 0, mNbRows - 1);
                 break;
        case 1 : iMin = clamp(minGridCoords[0], 0, mNbColumns - 1);
                 iMax = clamp(maxGridCoords[0], 0, mNbColumns - 1);
                 jMin = clamp(minGridCoords[2], 0, mNbRows - 1);
                 jMax = clamp(maxGridCoords[2], 0, mNbRows - 1);
                 break;
        case 2 : iMin = clamp(minGridCoords[0], 0, mNbColumns - 1);
                 iMax = clamp(maxGridCoords[0], 0, mNbColumns - 1);
                 jMin = clamp(minGridCoords[1], 0, mNbRows - 1);
                 jMax = clamp(maxGridCoords[1], 0, mNbRows - 1);
                 break;
   }

   assert(iMin >= 0 && iMin < mNbColumns);
   assert(iMax >= 0 && iMax < mNbColumns);
   assert(jMin >= 0 && jMin < mNbRows);
   assert(jMax >= 0 && jMax < mNbRows);

   // For each sub-grid points (except the last ones one each dimension)
   for (int i = iMin; i < iMax; i++) {
       for (int j = jMin; j < jMax; j++) {

           // Compute the four point of the current quad
           const Vector3 p1 = getVertexAt(i, j);
           const Vector3 p2 = getVertexAt(i, j + 1);
           const Vector3 p3 = getVertexAt(i + 1, j);
           const Vector3 p4 = getVertexAt(i + 1, j + 1);

           // Generate the first triangle for the current grid rectangle
           triangleVertices.add(p1);
           triangleVertices.add(p2);
           triangleVertices.add(p3);

           // Compute the triangle normal
           Vector3 triangle1Normal = (p2 - p1).cross(p3 - p1).getUnit();

           // Use the triangle face normal as vertices normals (this is an aproximation. The correct
           // solution would be to compute all the normals of the neighbor triangles and use their
           // weighted average (with incident angle as weight) at the vertices. However, this solution
           // seems too expensive (it requires to compute the normal of all neighbor triangles instead
           // and compute the angle of incident edges with asin(). Maybe we could also precompute the
           // vertices normal at the HeightFieldShape constructor but it will require extra memory to
           // store them.
           triangleVerticesNormals.add(triangle1Normal);
           triangleVerticesNormals.add(triangle1Normal);
           triangleVerticesNormals.add(triangle1Normal);

           // Compute the shape ID
           shapeIds.add(computeTriangleShapeId(i, j, 0));

           // Generate the second triangle for the current grid rectangle
           triangleVertices.add(p3);
           triangleVertices.add(p2);
           triangleVertices.add(p4);

           // Compute the triangle normal
           Vector3 triangle2Normal = (p2 - p3).cross(p4 - p3).getUnit();

           // Use the triangle face normal as vertices normals (this is an aproximation. The correct
           // solution would be to compute all the normals of the neighbor triangles and use their
           // weighted average (with incident angle as weight) at the vertices. However, this solution
           // seems too expensive (it requires to compute the normal of all neighbor triangles instead
           // and compute the angle of incident edges with asin(). Maybe we could also precompute the
           // vertices normal at the HeightFieldShape constructor but it will require extra memory to
           // store them.
           triangleVerticesNormals.add(triangle2Normal);
           triangleVerticesNormals.add(triangle2Normal);
           triangleVerticesNormals.add(triangle2Normal);

           // Compute the shape ID
           shapeIds.add(computeTriangleShapeId(i, j, 1));
       }
   }
}