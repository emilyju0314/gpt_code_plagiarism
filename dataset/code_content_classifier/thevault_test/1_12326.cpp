bool RotateManipulator::Hit(Camera* camera, int32 mousePosX, int32 mousePosY)
    {
        // check if camera exists
        if (camera == nullptr)
        {
            return false;
        }

        // update the bounding volumes
        UpdateBoundingVolumes();

        // shoot ray ar the mouse position
        MCore::Ray mousePosRay  = camera->Unproject(mousePosX, mousePosY);

        // check if mouse ray hits the outer sphere of the manipulator
        if (mousePosRay.Intersects(m_outerBoundingSphere))
        {
            return true;
        }

        // return false if manipulator is not hit
        return false;
    }