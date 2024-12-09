void DynamicsSystem::resetSplitVelocities() {

    const uint32 nbRigidBodyComponents = mRigidBodyComponents.getNbEnabledComponents();
    for(uint32 i=0; i < nbRigidBodyComponents; i++) {
        mRigidBodyComponents.mSplitLinearVelocities[i].setToZero();
        mRigidBodyComponents.mSplitAngularVelocities[i].setToZero();
    }
}