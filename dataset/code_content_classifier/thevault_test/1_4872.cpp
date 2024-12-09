void BallAndSocketJoint::enableConeLimit(bool isLimitEnabled) {
    mWorld.mBallAndSocketJointsComponents.setIsConeLimitEnabled(mEntity, isLimitEnabled);

    resetLimits();
}