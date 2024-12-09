void Gui::resetWithValuesFromCurrentScene() {

    auto test = mApp->getCurrentSceneEngineSettings();
    mCheckboxSleeping->set_checked(mApp->getCurrentSceneEngineSettings().isSleepingEnabled);
    mCheckboxGravity->set_checked(mApp->getCurrentSceneEngineSettings().isGravityEnabled);

    std::ostringstream out;
    out << std::setprecision(1) << std::fixed << (mApp->getCurrentSceneEngineSettings().timeStep.count() * 1000);
    mTextboxTimeStep->set_value(out.str());

    mTextboxVelocityIterations->set_value(std::to_string(mApp->getCurrentSceneEngineSettings().nbVelocitySolverIterations));
    mTextboxPositionIterations->set_value(std::to_string(mApp->getCurrentSceneEngineSettings().nbPositionSolverIterations));

    out.str("");
    out << std::setprecision(0) << std::fixed << (mApp->getCurrentSceneEngineSettings().timeBeforeSleep * 1000);
    mTextboxTimeSleep->set_value(out.str());

    out.str("");
    out << std::setprecision(2) << std::fixed << (mApp->getCurrentSceneEngineSettings().sleepLinearVelocity);
    mTextboxSleepLinearVel->set_value(out.str());

    out.str("");
    out << std::setprecision(2) << std::fixed << (mApp->getCurrentSceneEngineSettings().sleepAngularVelocity);
    mTextboxSleepAngularVel->set_value(out.str());
}