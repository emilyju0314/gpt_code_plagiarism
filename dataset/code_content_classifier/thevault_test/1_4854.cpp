void DynamicsSystem::integrateRigidBodiesVelocities(decimal timeStep) {

    RP3D_PROFILE("DynamicsSystem::integrateRigidBodiesVelocities()", mProfiler);

    // Reset the split velocities of the bodies
    resetSplitVelocities();

    // Integration component velocities using force/torque
    const uint32 nbEnabledRigidBodyComponents = mRigidBodyComponents.getNbEnabledComponents();
    for (uint32 i=0; i < nbEnabledRigidBodyComponents; i++) {

        assert(mRigidBodyComponents.mSplitLinearVelocities[i] == Vector3(0, 0, 0));
        assert(mRigidBodyComponents.mSplitAngularVelocities[i] == Vector3(0, 0, 0));

        const Vector3& linearVelocity = mRigidBodyComponents.mLinearVelocities[i];
        const Vector3& angularVelocity = mRigidBodyComponents.mAngularVelocities[i];

        // Integrate the external force to get the new velocity of the body
        mRigidBodyComponents.mConstrainedLinearVelocities[i] = linearVelocity + timeStep * mRigidBodyComponents.mInverseMasses[i] *
                                                               mRigidBodyComponents.mLinearLockAxisFactors[i] * mRigidBodyComponents.mExternalForces[i];
        mRigidBodyComponents.mConstrainedAngularVelocities[i] = angularVelocity + timeStep * mRigidBodyComponents.mAngularLockAxisFactors[i] *
                                                                (mRigidBodyComponents.mInverseInertiaTensorsWorld[i] * mRigidBodyComponents.mExternalTorques[i]);
    }

    // Apply gravity force
    if (mIsGravityEnabled) {

        const uint32 nbRigidBodyComponents = mRigidBodyComponents.getNbEnabledComponents();
        for (uint32 i=0; i < nbRigidBodyComponents; i++) {

            // If the gravity has to be applied to this rigid body
            if (mRigidBodyComponents.mIsGravityEnabled[i]) {

                // Integrate the gravity force
                mRigidBodyComponents.mConstrainedLinearVelocities[i] = mRigidBodyComponents.mConstrainedLinearVelocities[i] + timeStep *
                                                                       mRigidBodyComponents.mInverseMasses[i] * mRigidBodyComponents.mLinearLockAxisFactors[i] *
                                                                       mRigidBodyComponents.mMasses[i] * mGravity;
            }
        }
    }

    // Apply the velocity damping
    // Damping force : F_c = -c' * v (c=damping factor)
    // Differential Equation      : m * dv/dt = -c' * v
    //                              => dv/dt = -c * v (with c=c'/m)
    //                              => dv/dt + c * v = 0
    // Solution      : v(t) = v0 * e^(-c * t)
    //                 => v(t + dt) = v0 * e^(-c(t + dt))
    //                              = v0 * e^(-c * t) * e^(-c * dt)
    //                              = v(t) * e^(-c * dt)
    //                 => v2 = v1 * e^(-c * dt)
    // Using Padé's approximation of the exponential function:
    // Reference: https://mathworld.wolfram.com/PadeApproximant.html
    //                   e^x ~ 1 / (1 - x)
    //                      => e^(-c * dt) ~ 1 / (1 + c * dt)
    //                      => v2 = v1 * 1 / (1 + c * dt)
    const uint32 nbRigidBodyComponents = mRigidBodyComponents.getNbEnabledComponents();
    for (uint32 i=0; i < nbRigidBodyComponents; i++) {

        const decimal linDampingFactor = mRigidBodyComponents.mLinearDampings[i];
        const decimal angDampingFactor = mRigidBodyComponents.mAngularDampings[i];
        const decimal linearDamping = decimal(1.0) / (decimal(1.0) + linDampingFactor * timeStep);
        const decimal angularDamping = decimal(1.0) / (decimal(1.0) + angDampingFactor * timeStep);
        mRigidBodyComponents.mConstrainedLinearVelocities[i] = mRigidBodyComponents.mConstrainedLinearVelocities[i] * linearDamping;
        mRigidBodyComponents.mConstrainedAngularVelocities[i] = mRigidBodyComponents.mConstrainedAngularVelocities[i] * angularDamping;
    }
}