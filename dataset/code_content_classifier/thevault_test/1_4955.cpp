void RigidBody::setIsSleeping(bool isSleeping) {

    bool isBodySleeping = mWorld.mRigidBodyComponents.getIsSleeping(mEntity);

    if (isBodySleeping == isSleeping) return;

    // If the body is not active, do nothing (it is sleeping)
    if (!mWorld.mCollisionBodyComponents.getIsActive(mEntity)) {
        assert(isBodySleeping);
        return;
    }

    if (isSleeping) {
        mWorld.mRigidBodyComponents.setSleepTime(mEntity, decimal(0.0));
    }
    else {
        if (isBodySleeping) {
            mWorld.mRigidBodyComponents.setSleepTime(mEntity, decimal(0.0));
        }
    }

    mWorld.mRigidBodyComponents.setIsSleeping(mEntity, isSleeping);

    // Notify all the components
    mWorld.setBodyDisabled(mEntity, isSleeping);

    // Update the currently overlapping pairs
    resetOverlappingPairs();

    if (isSleeping) {

        mWorld.mRigidBodyComponents.setLinearVelocity(mEntity, Vector3::zero());
        mWorld.mRigidBodyComponents.setAngularVelocity(mEntity, Vector3::zero());
        mWorld.mRigidBodyComponents.setExternalForce(mEntity, Vector3::zero());
        mWorld.mRigidBodyComponents.setExternalTorque(mEntity, Vector3::zero());
    }

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
         "Body " + std::to_string(mEntity.id) + ": Set isSleeping=" +
         (isSleeping ? "true" : "false"),  __FILE__, __LINE__);
}