void RigidBody::setIsActive(bool isActive) {

    // If the state does not change
    if (mWorld.mCollisionBodyComponents.getIsActive(mEntity) == isActive) return;

    setIsSleeping(!isActive);

    CollisionBody::setIsActive(isActive);
}