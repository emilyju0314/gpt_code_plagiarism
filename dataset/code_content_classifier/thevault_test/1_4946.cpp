void RigidBody::enableGravity(bool isEnabled) {
    mWorld.mRigidBodyComponents.setIsGravityEnabled(mEntity, isEnabled);

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set isGravityEnabled=" +
             (isEnabled ? "true" : "false"),  __FILE__, __LINE__);
}