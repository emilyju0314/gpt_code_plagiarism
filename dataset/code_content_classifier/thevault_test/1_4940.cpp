void RigidBody::updateLocalInertiaTensorFromColliders() {

    // Compute the local-space inertia tensor
    Vector3 inertiaTensorLocal;
    decimal totalMass;
    computeMassAndInertiaTensorLocal(inertiaTensorLocal, totalMass);

    mWorld.mRigidBodyComponents.setLocalInertiaTensor(mEntity, inertiaTensorLocal);

    // If it is a dynamic body
    const BodyType type = mWorld.mRigidBodyComponents.getBodyType(mEntity);
    if (type == BodyType::DYNAMIC) {

        // Compute the inverse local inertia tensor
        Vector3 inverseInertiaTensorLocal(inertiaTensorLocal.x != decimal(0.0) ? decimal(1.0) / inertiaTensorLocal.x : 0,
                                          inertiaTensorLocal.y != decimal(0.0) ? decimal(1.0) / inertiaTensorLocal.y : 0,
                                          inertiaTensorLocal.z != decimal(0.0) ? decimal(1.0) / inertiaTensorLocal.z : 0);
        mWorld.mRigidBodyComponents.setInverseInertiaTensorLocal(mEntity, inverseInertiaTensorLocal);
    }

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set inertiaTensorLocal=" + inertiaTensorLocal.to_string(),  __FILE__, __LINE__);
}