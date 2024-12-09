void RigidBody::setIsAllowedToSleep(bool isAllowedToSleep) {

    mWorld.mRigidBodyComponents.setIsAllowedToSleep(mEntity, isAllowedToSleep);

    if (!isAllowedToSleep) setIsSleeping(false);

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set isAllowedToSleep=" +
             (isAllowedToSleep ? "true" : "false"),  __FILE__, __LINE__);
}