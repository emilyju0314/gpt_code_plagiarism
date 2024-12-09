void RigidBody::updateMassPropertiesFromColliders() {

    const Vector3 oldCenterOfMassWorld = mWorld.mRigidBodyComponents.getCenterOfMassWorld(mEntity);

    // Compute the local center of mass
    Vector3 centerOfMassLocal = computeCenterOfMass();

    const Vector3 centerOfMassWorld = mWorld.mTransformComponents.getTransform(mEntity) * centerOfMassLocal;

    // Set the center of mass
    mWorld.mRigidBodyComponents.setCenterOfMassLocal(mEntity, centerOfMassLocal);
    mWorld.mRigidBodyComponents.setCenterOfMassWorld(mEntity, centerOfMassWorld);

    // If it is a dynamic body
    const BodyType type = mWorld.mRigidBodyComponents.getBodyType(mEntity);
    if (type == BodyType::DYNAMIC) {

        // Update the linear velocity of the center of mass
        Vector3 linearVelocity = mWorld.mRigidBodyComponents.getLinearVelocity(mEntity);
        const Vector3& angularVelocity = mWorld.mRigidBodyComponents.getAngularVelocity(mEntity);
        linearVelocity += angularVelocity.cross(centerOfMassWorld - oldCenterOfMassWorld);
        mWorld.mRigidBodyComponents.setLinearVelocity(mEntity, linearVelocity);
    }

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set centerOfMassLocal=" + centerOfMassLocal.to_string(),  __FILE__, __LINE__);

    // Compute the mass and local-space inertia tensor
    Vector3 inertiaTensorLocal;
    decimal totalMass;
    computeMassAndInertiaTensorLocal(inertiaTensorLocal, totalMass);

    mWorld.mRigidBodyComponents.setLocalInertiaTensor(mEntity, inertiaTensorLocal);

    // If it is a dynamic body
    if (type == BodyType::DYNAMIC) {

        // Compute the inverse local inertia tensor
        Vector3 inverseInertiaTensorLocal(inertiaTensorLocal.x != decimal(0.0) ? decimal(1.0) / inertiaTensorLocal.x : 0,
                                          inertiaTensorLocal.y != decimal(0.0) ? decimal(1.0) / inertiaTensorLocal.y : 0,
                                          inertiaTensorLocal.z != decimal(0.0) ? decimal(1.0) / inertiaTensorLocal.z : 0);
        mWorld.mRigidBodyComponents.setInverseInertiaTensorLocal(mEntity, inverseInertiaTensorLocal);
    }

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set inertiaTensorLocal=" + inertiaTensorLocal.to_string(),  __FILE__, __LINE__);

    // Set the mass
    mWorld.mRigidBodyComponents.setMass(mEntity, totalMass);

    // If it is a dynamic body
    if (type == BodyType::DYNAMIC) {

        // Compute the inverse mass
        if (totalMass > decimal(0.0)) {
            mWorld.mRigidBodyComponents.setMassInverse(mEntity, decimal(1.0) / totalMass);
        }
        else {
            mWorld.mRigidBodyComponents.setMassInverse(mEntity, decimal(0.0));
        }
    }

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set mass=" + std::to_string(totalMass),  __FILE__, __LINE__);
}