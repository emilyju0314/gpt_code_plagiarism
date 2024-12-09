void RigidBody::setLocalCenterOfMass(const Vector3& centerOfMass) {

    const Vector3 oldCenterOfMass = mWorld.mRigidBodyComponents.getCenterOfMassWorld(mEntity);
    mWorld.mRigidBodyComponents.setCenterOfMassLocal(mEntity, centerOfMass);

    // Compute the center of mass in world-space coordinates
    mWorld.mRigidBodyComponents.setCenterOfMassWorld(mEntity, mWorld.mTransformComponents.getTransform(mEntity) * centerOfMass);

    // Update the linear velocity of the center of mass
    Vector3 linearVelocity = mWorld.mRigidBodyComponents.getLinearVelocity(mEntity);
    const Vector3& angularVelocity = mWorld.mRigidBodyComponents.getAngularVelocity(mEntity);
    const Vector3& centerOfMassWorld = mWorld.mRigidBodyComponents.getCenterOfMassWorld(mEntity);
    linearVelocity += angularVelocity.cross(centerOfMassWorld - oldCenterOfMass);
    mWorld.mRigidBodyComponents.setLinearVelocity(mEntity, linearVelocity);

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set centerOfMassLocal=" + centerOfMass.to_string(),  __FILE__, __LINE__);
}