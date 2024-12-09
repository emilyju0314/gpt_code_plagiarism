void SceneDemo::updatePhysics() {

    // Clear contacts points
    mSnapshotsContactPoints.clear();

    if (mIsPhysicsWorldSimulated) {

        // Take a simulation step
        mPhysicsWorld->update(mEngineSettings.timeStep.count());
    }
}