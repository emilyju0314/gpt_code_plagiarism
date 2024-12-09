void RigidBody::applyLocalForceAtLocalPosition(const Vector3& force, const Vector3& point) {

    // Convert the local-space force to world-space
    const Vector3 worldForce = mWorld.mTransformComponents.getTransform(mEntity).getOrientation() * force;

    applyWorldForceAtLocalPosition(worldForce, point);
}