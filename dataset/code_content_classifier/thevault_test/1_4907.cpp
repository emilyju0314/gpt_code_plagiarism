void CollisionDetectionSystem::reduceContactPoints(ContactManifoldInfo& manifold, const Transform& shape1ToWorldTransform,
                                             const Array<ContactPointInfo>& potentialContactPoints) const {

    assert(manifold.nbPotentialContactPoints > MAX_CONTACT_POINTS_IN_MANIFOLD);

    // The following algorithm only works to reduce to a maximum of 4 contact points
    assert(MAX_CONTACT_POINTS_IN_MANIFOLD == 4);

    // Array of the candidate contact points indices in the manifold. Every time that we have found a
    // point we want to keep, we will remove it from this array
    uint candidatePointsIndices[NB_MAX_CONTACT_POINTS_IN_POTENTIAL_MANIFOLD];
    uint8 nbCandidatePoints = manifold.nbPotentialContactPoints;
    for (uint8 i=0 ; i < manifold.nbPotentialContactPoints; i++) {
        candidatePointsIndices[i] = manifold.potentialContactPointsIndices[i];
    }

    int8 nbReducedPoints = 0;

    uint32 pointsToKeepIndices[MAX_CONTACT_POINTS_IN_MANIFOLD];
    for (int8 i=0; i<MAX_CONTACT_POINTS_IN_MANIFOLD; i++) {
        pointsToKeepIndices[i] = 0;
    }

    //  Compute the initial contact point we need to keep.
    // The first point we keep is always the point in a given
    // constant direction (in order to always have same contact points
    // between frames for better stability)

    const Transform worldToShape1Transform = shape1ToWorldTransform.getInverse();

    // Compute the contact normal of the manifold (we use the first contact point)
    // in the local-space of the first collision shape
    const Vector3 contactNormalShape1Space = worldToShape1Transform.getOrientation() * potentialContactPoints[candidatePointsIndices[0]].normal;

    // Compute a search direction
    const Vector3 searchDirection(1, 1, 1);
    decimal maxDotProduct = DECIMAL_SMALLEST;
    uint32 elementIndexToKeep = 0;
    for (uint32 i=0; i < nbCandidatePoints; i++) {

        const ContactPointInfo& element = potentialContactPoints[candidatePointsIndices[i]];
        decimal dotProduct = searchDirection.dot(element.localPoint1);
        if (dotProduct > maxDotProduct) {
            maxDotProduct = dotProduct;
            elementIndexToKeep = i;
            nbReducedPoints = 1;
        }
    }
    pointsToKeepIndices[0] = candidatePointsIndices[elementIndexToKeep];
    removeItemAtInArray(candidatePointsIndices, elementIndexToKeep, nbCandidatePoints);
    //candidatePointsIndices.removeAt(elementIndexToKeep);
    assert(nbReducedPoints == 1);

    // Compute the second contact point we need to keep.
    // The second point we keep is the one farthest away from the first point.

    decimal maxDistance = decimal(0.0);
    elementIndexToKeep = 0;
    for (uint32 i=0; i < nbCandidatePoints; i++) {

        const ContactPointInfo& element = potentialContactPoints[candidatePointsIndices[i]];
        const ContactPointInfo& pointToKeep0 = potentialContactPoints[pointsToKeepIndices[0]];

        assert(candidatePointsIndices[i] != pointsToKeepIndices[0]);

        const decimal distance = (pointToKeep0.localPoint1 - element.localPoint1).lengthSquare();
        if (distance >= maxDistance) {
            maxDistance = distance;
            elementIndexToKeep = i;
            nbReducedPoints = 2;
        }

    }
    pointsToKeepIndices[1] = candidatePointsIndices[elementIndexToKeep];
    removeItemAtInArray(candidatePointsIndices, elementIndexToKeep, nbCandidatePoints);
    assert(nbReducedPoints == 2);

    // Compute the third contact point we need to keep.
    // The third point is the one producing the triangle with the larger area
    // with first and second point.

    // We compute the most positive or most negative triangle area (depending on winding)
    uint32 thirdPointMaxAreaIndex = 0;
    uint32 thirdPointMinAreaIndex = 0;
    decimal minArea = decimal(0.0);
    decimal maxArea = decimal(0.0);
    bool isPreviousAreaPositive = true;
    for (uint32 i=0; i < nbCandidatePoints; i++) {

        const ContactPointInfo& element = potentialContactPoints[candidatePointsIndices[i]];
        const ContactPointInfo& pointToKeep0 = potentialContactPoints[pointsToKeepIndices[0]];
        const ContactPointInfo& pointToKeep1 = potentialContactPoints[pointsToKeepIndices[1]];

        assert(candidatePointsIndices[i] != pointsToKeepIndices[0]);
        assert(candidatePointsIndices[i] != pointsToKeepIndices[1]);

        const Vector3 newToFirst = pointToKeep0.localPoint1 - element.localPoint1;
        const Vector3 newToSecond = pointToKeep1.localPoint1 - element.localPoint1;

        // Compute the triangle area
        decimal area = newToFirst.cross(newToSecond).dot(contactNormalShape1Space);

        if (area >= maxArea) {
            maxArea = area;
            thirdPointMaxAreaIndex = i;
        }
        if (area <= minArea) {
            minArea = area;
            thirdPointMinAreaIndex = i;
        }
    }
    assert(minArea <= decimal(0.0));
    assert(maxArea >= decimal(0.0));
    if (maxArea > (-minArea)) {
        isPreviousAreaPositive = true;
        pointsToKeepIndices[2] = candidatePointsIndices[thirdPointMaxAreaIndex];
        removeItemAtInArray(candidatePointsIndices, thirdPointMaxAreaIndex, nbCandidatePoints);
    }
    else {
        isPreviousAreaPositive = false;
        pointsToKeepIndices[2] = candidatePointsIndices[thirdPointMinAreaIndex];
        removeItemAtInArray(candidatePointsIndices, thirdPointMinAreaIndex, nbCandidatePoints);
    }
    nbReducedPoints = 3;

    // Compute the 4th point by choosing the triangle that adds the most
    // triangle area to the previous triangle and has opposite sign area (opposite winding)

    decimal largestArea = decimal(0.0); // Largest area (positive or negative)
    elementIndexToKeep = 0;
    nbReducedPoints = 4;
    decimal area;

    // For each remaining candidate points
    for (uint32 i=0; i < nbCandidatePoints; i++) {

        const ContactPointInfo& element = potentialContactPoints[candidatePointsIndices[i]];

        assert(candidatePointsIndices[i] != pointsToKeepIndices[0]);
        assert(candidatePointsIndices[i] != pointsToKeepIndices[1]);
        assert(candidatePointsIndices[i] != pointsToKeepIndices[2]);

        // For each edge of the triangle made by the first three points
        for (uint32 j=0; j<3; j++) {

            uint32 edgeVertex1Index = j;
            uint32 edgeVertex2Index = j < 2 ? j + 1 : 0;

            const ContactPointInfo& pointToKeepEdgeV1 = potentialContactPoints[pointsToKeepIndices[edgeVertex1Index]];
            const ContactPointInfo& pointToKeepEdgeV2 = potentialContactPoints[pointsToKeepIndices[edgeVertex2Index]];

            const Vector3 newToFirst = pointToKeepEdgeV1.localPoint1 - element.localPoint1;
            const Vector3 newToSecond = pointToKeepEdgeV2.localPoint1 - element.localPoint1;

            // Compute the triangle area
            area = newToFirst.cross(newToSecond).dot(contactNormalShape1Space);

            // We are looking at the triangle with maximal area (positive or negative).
            // If the previous area is positive, we are looking at negative area now.
            // If the previous area is negative, we are looking at the positive area now.
            if (isPreviousAreaPositive && area <= largestArea) {
                largestArea = area;
                elementIndexToKeep = i;
            }
            else if (!isPreviousAreaPositive && area >= largestArea) {
                largestArea = area;
                elementIndexToKeep = i;
            }
        }
    }
    pointsToKeepIndices[3] = candidatePointsIndices[elementIndexToKeep];
    removeItemAtInArray(candidatePointsIndices, elementIndexToKeep, nbCandidatePoints);

    // Only keep the four selected contact points in the manifold
    manifold.potentialContactPointsIndices[0] = pointsToKeepIndices[0];
    manifold.potentialContactPointsIndices[1] = pointsToKeepIndices[1];
    manifold.potentialContactPointsIndices[2] = pointsToKeepIndices[2];
    manifold.potentialContactPointsIndices[3] = pointsToKeepIndices[3];
    manifold.nbPotentialContactPoints = 4;
}