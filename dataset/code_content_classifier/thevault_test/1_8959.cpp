void VisualizationManagerForCamera::update(float wall_dt, float ros_dt)
            {
                VisualizationManager::update(wall_dt, ros_dt);

                if (display->isEnabled())
                {
                    display->update(wall_dt, ros_dt);
                    //display->printOutFieldOfViews();
                }
            }