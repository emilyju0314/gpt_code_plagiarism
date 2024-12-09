void RigidBody::updateLocalCenterOfMassFromColliders() {

    const Vector3 oldCenterOfMassWorld = mWorld.mRigidBodyComponents.getCenterOfMassWorld(mEntity);

    Vector3 centerOfMassLocal = computeCenterOfMass();

    const Vector3 centerOfMassWorld = mWorld.mTransformComponents.getTransform(mEntity) * centerOfMassLocal;

    // Set the center of mass
    mWorld.mRigidBodyComponents.setCenterOfMassLocal(mEntity, centerOfMassLocal);
    mWorld.mRigidBodyComponents.setCenterOfMassWorld(mEntity, centerOfMassWorld);

    // Update the linear velocity of the center of mass
    Vector3 linearVelocity = mWorld.mRigidBodyComponents.getLinearVelocity(mEntity);
    const Vector3& angularVelocity = mWorld.mRigidBodyComponents.getAngularVelocity(mEntity);
    linearVelocity += angularVelocity.cross(centerOfMassWorld - oldCenterOfMassWorld);
    mWorld.mRigidBodyComponents.setLinearVelocity(mEntity, linearVelocity);

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set centerOfMassLocal=" + centerOfMassLocal.to_string(),  __FILE__, __LINE__);
}