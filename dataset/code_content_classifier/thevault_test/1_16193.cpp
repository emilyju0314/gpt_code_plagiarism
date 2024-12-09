void QuadScene::updatePhysics() {
    double elapsedTime = static_cast<double>(mEngineSettings.elapsedTime) - simStartTime;

    mDrone->updatePhysics(mEngineSettings.timeStep);
    SceneDemo::updatePhysics();
}