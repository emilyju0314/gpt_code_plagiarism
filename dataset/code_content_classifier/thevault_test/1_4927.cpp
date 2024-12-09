rp3d::decimal SceneDemo::notifyRaycastHit(const rp3d::RaycastInfo& raycastInfo) {

    rp3d::RigidBody* body = dynamic_cast<rp3d::RigidBody*>(raycastInfo.body);
    mMovingBody = body;
    const rp3d::Transform localToWorldTransform = raycastInfo.collider->getLocalToWorldTransform();
    mMovingBodyLocalPoint = localToWorldTransform.getInverse() * raycastInfo.worldPoint;

    return raycastInfo.hitFraction;
}