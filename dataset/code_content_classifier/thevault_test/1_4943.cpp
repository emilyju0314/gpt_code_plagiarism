void RigidBody::setMass(decimal mass) {

    if (mass < decimal(0.0)) {

        RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Error, Logger::Category::Body,
                 "Error when setting mass of body " + std::to_string(mEntity.id) + ": mass cannot be negative",  __FILE__, __LINE__);

        return;
    }

    mWorld.mRigidBodyComponents.setMass(mEntity, mass);

    // If it is a dynamic body
    const BodyType type = mWorld.mRigidBodyComponents.getBodyType(mEntity);
    if (type == BodyType::DYNAMIC) {

        if (mass > decimal(0.0)) {
            mWorld.mRigidBodyComponents.setMassInverse(mEntity, decimal(1.0) / mass);
        }
        else {
            mWorld.mRigidBodyComponents.setMassInverse(mEntity, decimal(0.0));

        }
    }

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set mass=" + std::to_string(mass),  __FILE__, __LINE__);
}