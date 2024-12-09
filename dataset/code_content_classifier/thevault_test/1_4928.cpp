void RigidBody::setType(BodyType type) {

    if (mWorld.mRigidBodyComponents.getBodyType(mEntity) == type) return;

    mWorld.mRigidBodyComponents.setBodyType(mEntity, type);

    // If it is a static body
    if (type == BodyType::STATIC) {

        // Reset the velocity to zero
        mWorld.mRigidBodyComponents.setLinearVelocity(mEntity, Vector3::zero());
        mWorld.mRigidBodyComponents.setAngularVelocity(mEntity, Vector3::zero());
    }

    // If it is a static or a kinematic body
    if (type == BodyType::STATIC || type == BodyType::KINEMATIC) {

        // Reset the inverse mass and inverse inertia tensor to zero
        mWorld.mRigidBodyComponents.setMassInverse(mEntity, decimal(0));
        mWorld.mRigidBodyComponents.setInverseInertiaTensorLocal(mEntity, Vector3::zero());
    }
    else {  // If it is a dynamic body

        const decimal mass = mWorld.mRigidBodyComponents.getMass(mEntity);

        if (mass > decimal(0.0)) {
            mWorld.mRigidBodyComponents.setMassInverse(mEntity, decimal(1.0) / mass) ;
        }
        else {
            mWorld.mRigidBodyComponents.setMassInverse(mEntity, decimal(0.0));
        }

        // Compute the inverse local inertia tensor
        const Vector3& inertiaTensorLocal = mWorld.mRigidBodyComponents.getLocalInertiaTensor(mEntity);
        Vector3 inverseInertiaTensorLocal(inertiaTensorLocal.x != decimal(0.0) ? decimal(1.0) / inertiaTensorLocal.x : 0,
                                          inertiaTensorLocal.y != decimal(0.0) ? decimal(1.0) / inertiaTensorLocal.y : 0,
                                          inertiaTensorLocal.z != decimal(0.0) ? decimal(1.0) / inertiaTensorLocal.z : 0);
        mWorld.mRigidBodyComponents.setInverseInertiaTensorLocal(mEntity, inverseInertiaTensorLocal);
    }

    // Awake the body
    setIsSleeping(false);

    // Update the active status of currently overlapping pairs
    resetOverlappingPairs();

    // Reset the force and torque on the body
    mWorld.mRigidBodyComponents.setExternalForce(mEntity, Vector3::zero());
    mWorld.mRigidBodyComponents.setExternalTorque(mEntity, Vector3::zero());

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set type=" +
             (type == BodyType::STATIC ? "Static" : (type == BodyType::DYNAMIC ? "Dynamic" : "Kinematic")),  __FILE__, __LINE__);
}