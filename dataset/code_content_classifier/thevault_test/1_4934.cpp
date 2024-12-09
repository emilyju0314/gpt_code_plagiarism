void RigidBody::applyLocalForceAtCenterOfMass(const Vector3& force) {

    // Convert the local-space force to world-space
    const Vector3 worldForce = mWorld.mTransformComponents.getTransform(mEntity).getOrientation() * force;

    applyWorldForceAtCenterOfMass(worldForce);
}