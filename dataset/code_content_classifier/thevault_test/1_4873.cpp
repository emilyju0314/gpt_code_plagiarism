void BallAndSocketJoint::setConeLimitHalfAngle(decimal coneHalfAngle) {

    if (mWorld.mBallAndSocketJointsComponents.getConeLimitHalfAngle(mEntity) != coneHalfAngle) {

        mWorld.mBallAndSocketJointsComponents.setConeLimitHalfAngle(mEntity, coneHalfAngle);

        resetLimits();
    }
}