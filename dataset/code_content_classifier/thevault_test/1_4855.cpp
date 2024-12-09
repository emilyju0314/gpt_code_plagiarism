void DynamicsSystem::resetBodiesForceAndTorque() {

    // For each body of the world
    const uint32 nbRigidBodyComponents = mRigidBodyComponents.getNbComponents();
    for (uint32 i=0; i < nbRigidBodyComponents; i++) {
        mRigidBodyComponents.mExternalForces[i].setToZero();
        mRigidBodyComponents.mExternalTorques[i].setToZero();
    }
}