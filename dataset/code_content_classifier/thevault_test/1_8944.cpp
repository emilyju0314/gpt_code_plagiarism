void VisualizationManagerForPhoto::update(float wall_dt, float ros_dt)
            {
                VisualizationManager::update(wall_dt, ros_dt);

                display->update(wall_dt, ros_dt);
            }