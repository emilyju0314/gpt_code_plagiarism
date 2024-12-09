decimal CollisionDetectionSystem::computePotentialManifoldLargestContactDepth(const ContactManifoldInfo& manifold,
                                                                        const Array<ContactPointInfo>& potentialContactPoints) const {

    decimal largestDepth = 0.0f;

    assert(manifold.nbPotentialContactPoints > 0);

    for (uint32 i=0; i < manifold.nbPotentialContactPoints; i++) {
        decimal depth = potentialContactPoints[manifold.potentialContactPointsIndices[i]].penetrationDepth;

        if (depth > largestDepth) {
            largestDepth = depth;
        }
    }

    return largestDepth;
}