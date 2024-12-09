void RigidBody::setLinearDamping(decimal linearDamping) {
    assert(linearDamping >= decimal(0.0));

    if (linearDamping >= decimal(0.0)) {

        mWorld.mRigidBodyComponents.setLinearDamping(mEntity, linearDamping);

        RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
                 "Body " + std::to_string(mEntity.id) + ": Set linearDamping=" + std::to_string(linearDamping),  __FILE__, __LINE__);
    }
    else {

        RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Error, Logger::Category::Body,
                 "Error when setting the linear damping of body " + std::to_string(mEntity.id) + ": linear damping cannot be negative",  __FILE__, __LINE__);
    }
}