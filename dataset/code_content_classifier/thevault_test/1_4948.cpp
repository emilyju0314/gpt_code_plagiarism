void RigidBody::setAngularDamping(decimal angularDamping) {
    assert(angularDamping >= decimal(0.0));

    if (angularDamping >= decimal(0.0)) {

        mWorld.mRigidBodyComponents.setAngularDamping(mEntity, angularDamping);

        RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
                 "Body " + std::to_string(mEntity.id) + ": Set angularDamping=" + std::to_string(angularDamping),  __FILE__, __LINE__);
    }
    else {
        RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Error, Logger::Category::Body,
                 "Error when setting the angular damping of body " + std::to_string(mEntity.id) + ": angular damping cannot be negative",  __FILE__, __LINE__);
    }
}