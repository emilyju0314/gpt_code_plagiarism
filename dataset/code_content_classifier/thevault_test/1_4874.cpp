decimal BallAndSocketJoint::getConeHalfAngle() const {

    // Get the bodies entities
    const Entity body1Entity = mWorld.mJointsComponents.getBody1Entity(mEntity);
    const Entity body2Entity = mWorld.mJointsComponents.getBody2Entity(mEntity);

    const Transform& transformBody1 = mWorld.mTransformComponents.getTransform(body1Entity);
    const Transform& transformBody2 = mWorld.mTransformComponents.getTransform(body2Entity);

    // Convert local-space cone axis of bodies to world-space
    const Vector3 r1Local = mWorld.mBallAndSocketJointsComponents.getLocalAnchorPointBody1(mEntity) - mWorld.mRigidBodyComponents.getCenterOfMassLocal(body1Entity);
    const Vector3 r2Local = mWorld.mBallAndSocketJointsComponents.getLocalAnchorPointBody2(mEntity) - mWorld.mRigidBodyComponents.getCenterOfMassLocal(body2Entity);
    const Vector3 r1World = transformBody1.getOrientation() * r1Local;
    const Vector3 r2World = transformBody2.getOrientation() * r2Local;

    return SolveBallAndSocketJointSystem::computeCurrentConeHalfAngle(r1World.getUnit(), -r2World.getUnit());
}