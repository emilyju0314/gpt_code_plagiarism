void CollisionDetectionSystem::removeDuplicatedContactPointsInManifold(ContactManifoldInfo& manifold,
                                                                       const Array<ContactPointInfo>& potentialContactPoints) const {

    RP3D_PROFILE("CollisionDetectionSystem::removeDuplicatedContactPointsInManifold()", mProfiler);

    const decimal distThresholdSqr = SAME_CONTACT_POINT_DISTANCE_THRESHOLD * SAME_CONTACT_POINT_DISTANCE_THRESHOLD;

    // For each contact point of the manifold
    for (uint32 i=0; i < manifold.nbPotentialContactPoints; i++) {
        for (uint32 j=i+1; j < manifold.nbPotentialContactPoints; j++) {

            const ContactPointInfo& point1 = potentialContactPoints[manifold.potentialContactPointsIndices[i]];
            const ContactPointInfo& point2 = potentialContactPoints[manifold.potentialContactPointsIndices[j]];

            // Compute the distance between the two contact points
            const decimal distSqr = (point2.localPoint1 - point1.localPoint1).lengthSquare();

            // We have a found a duplicated contact point
            if (distSqr < distThresholdSqr) {

                // Remove the duplicated contact point
                manifold.potentialContactPointsIndices[j] = manifold.potentialContactPointsIndices[manifold.nbPotentialContactPoints-1];
                manifold.nbPotentialContactPoints--;

                j--;
            }
        }
    }
}