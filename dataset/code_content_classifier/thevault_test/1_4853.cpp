void DynamicsSystem::updateBodiesState() {

    RP3D_PROFILE("DynamicsSystem::updateBodiesState()", mProfiler);

    const uint32 nbRigidBodyComponents = mRigidBodyComponents.getNbEnabledComponents();
    for (uint32 i=0; i < nbRigidBodyComponents; i++) {

        // Update the linear and angular velocity of the body
        mRigidBodyComponents.mLinearVelocities[i] = mRigidBodyComponents.mConstrainedLinearVelocities[i];
        mRigidBodyComponents.mAngularVelocities[i] = mRigidBodyComponents.mConstrainedAngularVelocities[i];

        // Update the position of the center of mass of the body
        mRigidBodyComponents.mCentersOfMassWorld[i] = mRigidBodyComponents.mConstrainedPositions[i];

        // Update the orientation of the body
        const Quaternion& constrainedOrientation = mRigidBodyComponents.mConstrainedOrientations[i];
        mTransformComponents.getTransform(mRigidBodyComponents.mBodiesEntities[i]).setOrientation(constrainedOrientation.getUnit());
    }

    // Update the position of the body (using the new center of mass and new orientation)
    for (uint32 i=0; i < nbRigidBodyComponents; i++) {

        Transform& transform = mTransformComponents.getTransform(mRigidBodyComponents.mBodiesEntities[i]);
        const Vector3& centerOfMassWorld = mRigidBodyComponents.mCentersOfMassWorld[i];
        const Vector3& centerOfMassLocal = mRigidBodyComponents.mCentersOfMassLocal[i];
        transform.setPosition(centerOfMassWorld - transform.getOrientation() * centerOfMassLocal);
    }

    // Update the local-to-world transform of the colliders
    const uint32 nbColliderComponents = mColliderComponents.getNbEnabledComponents();
    for (uint32 i=0; i < nbColliderComponents; i++) {

        // Update the local-to-world transform of the collider
        mColliderComponents.mLocalToWorldTransforms[i] = mTransformComponents.getTransform(mColliderComponents.mBodiesEntities[i]) *
                                                           mColliderComponents.mLocalToBodyTransforms[i];
    }
}