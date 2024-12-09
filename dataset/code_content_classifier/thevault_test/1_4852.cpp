void DynamicsSystem::integrateRigidBodiesPositions(decimal timeStep, bool isSplitImpulseActive) {

    RP3D_PROFILE("DynamicsSystem::integrateRigidBodiesPositions()", mProfiler);

    const decimal isSplitImpulseFactor = isSplitImpulseActive ? decimal(1.0) : decimal(0.0);

    const uint32 nbRigidBodyComponents = mRigidBodyComponents.getNbEnabledComponents();
    for (uint32 i=0; i < nbRigidBodyComponents; i++) {

        // Get the constrained velocity
        Vector3 newLinVelocity = mRigidBodyComponents.mConstrainedLinearVelocities[i];
        Vector3 newAngVelocity = mRigidBodyComponents.mConstrainedAngularVelocities[i];

        // Add the split impulse velocity from Contact Solver (only used
        // to update the position)
        newLinVelocity += isSplitImpulseFactor * mRigidBodyComponents.mSplitLinearVelocities[i];
        newAngVelocity += isSplitImpulseFactor * mRigidBodyComponents.mSplitAngularVelocities[i];

        // Get current position and orientation of the body
        const Vector3& currentPosition = mRigidBodyComponents.mCentersOfMassWorld[i];
        const Quaternion& currentOrientation = mTransformComponents.getTransform(mRigidBodyComponents.mBodiesEntities[i]).getOrientation();

        // Update the new constrained position and orientation of the body
        mRigidBodyComponents.mConstrainedPositions[i] = currentPosition + newLinVelocity * timeStep;
        mRigidBodyComponents.mConstrainedOrientations[i] = currentOrientation + Quaternion(0, newAngVelocity) *
                                                           currentOrientation * decimal(0.5) * timeStep;
    }
}