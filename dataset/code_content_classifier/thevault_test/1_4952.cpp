void RigidBody::applyLocalTorque(const Vector3& torque) {

    // Convert the local-space torque to world-space
    const Vector3 worldTorque = mWorld.mTransformComponents.getTransform(mEntity).getOrientation() * torque;

    applyWorldTorque(worldTorque);
}