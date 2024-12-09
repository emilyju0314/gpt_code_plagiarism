Vector calcTotalForces(const State& s, const Model& model) {
    // create a working instance of the model, upon first entrance to this
    // function
    static Model* workingModel = NULL;
    if (workingModel == NULL) {
        workingModel = model.clone();
        workingModel->setUseVisualizer(false);
        // remove controllers to avoid infinite loop
        workingModel->updControllerSet().setSize(0);
        // disable any actuators when computing the total force
        auto& fs = workingModel->updForceSet();
        for (int i = 0; i < fs.getSize(); i++) {
            auto pathActuator = dynamic_cast<PathActuator*>(&fs[i]);
            if (pathActuator) {
                pathActuator->set_appliesForce(false);
            }
        }
        workingModel->finalizeFromProperties();
        workingModel->initSystem();
    }
    // initialize working state from s
    auto workingState = workingModel->updWorkingState();
    workingState.setTime(s.getTime());
    workingState.setQ(s.getQ());
    workingState.setU(s.getU());
    workingState.setZ(s.getZ());
    workingState.setY(s.getY());
    // generalized forces and torques should be accessed at a Dynamics stage
    workingModel->realizeDynamics(workingState);
    // get acting torques and body forces
    auto bodyForces = workingModel->getMultibodySystem()
        .getRigidBodyForces(workingState, Stage::Dynamics);
    auto generalizedForces = workingModel->getMultibodySystem()
        .getMobilityForces(workingState, Stage::Dynamics);
    // map body forces to joint forces
    Vector jointForces;
    workingModel->getMatterSubsystem()
        .multiplyBySystemJacobianTranspose(workingState, bodyForces, jointForces);
    // in our conviction we subtract their contribution
    return -1.0 * generalizedForces - jointForces;
}