void VisualizationManager::update(float wall_dt, float ros_dt)
    {
        // 1) Updates the frame transformer (clears the cache)
        frameTransformer->update();

        // 3) Updates the view controller
        viewController->update(wall_dt, ros_dt);

    }