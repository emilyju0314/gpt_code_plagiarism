void RigidBody::setLinearVelocity(const Vector3& linearVelocity) {

    // If it is a static body, we do nothing
    if (mWorld.mRigidBodyComponents.getBodyType(mEntity) == BodyType::STATIC) return;

    // Update the linear velocity of the current body state
    mWorld.mRigidBodyComponents.setLinearVelocity(mEntity, linearVelocity);

    // If the linear velocity is not zero, awake the body
    if (linearVelocity.lengthSquare() > decimal(0.0)) {
        setIsSleeping(false);
    }

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set linearVelocity=" + linearVelocity.to_string(),  __FILE__, __LINE__);
}