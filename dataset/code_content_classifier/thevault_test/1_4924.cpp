void SceneDemo::moveBodyWithMouse(double mousePosX, double mousePosY) {

    if (!mIsMovingBody) {

        // Find the body and the position of the mouse on that body (with raycasting)
        openglframework::Vector4 screenPoint1((mousePosX / mWindowWidth) * 2.0 - 1.0, ((mWindowHeight - mousePosY) / mWindowHeight) * 2.0 - 1.0, -1, 1);
        openglframework::Vector4 screenPoint2((mousePosX / mWindowWidth) * 2.0 - 1.0, ((mWindowHeight - mousePosY) / mWindowHeight) * 2.0 - 1.0, 1, 1);
        openglframework::Vector4 worldP1 = (mCamera.getTransformMatrix() * mCamera.getProjectionMatrix().getInverse()) * screenPoint1;
        openglframework::Vector4 worldP2 = (mCamera.getTransformMatrix() * mCamera.getProjectionMatrix().getInverse()) * screenPoint2;
        openglframework::Vector3 cameraPos = mCamera.getOrigin();
        rp3d::Vector3 worldPoint1(worldP1.x, worldP1.y, worldP1.z);
        rp3d::Vector3 worldPoint2(worldP2.x, worldP2.y, worldP2.z);
        rp3d::Ray ray(worldPoint1, worldPoint2);
        mPhysicsWorld->raycast(ray, this);
    }

    if (mMovingBody != nullptr) {
        openglframework::Vector4 previousScreenPos(mLastMouseX / mWindowWidth, (mWindowHeight - mLastMouseY) / mWindowHeight, 0, 0);
        openglframework::Vector4 currentScreenPos(mousePosX / mWindowWidth, (mWindowHeight - mousePosY) / mWindowHeight, 0, 0);
        openglframework::Vector4 forceScreen = currentScreenPos - previousScreenPos;
        openglframework::Vector4 f = mCamera.getTransformMatrix() * forceScreen * MOUSE_MOVE_BODY_FORCE;
        rp3d::Vector3 force(f.x, f.y, f.z);
        mMovingBody->applyWorldForceAtLocalPosition(force, mMovingBodyLocalPoint);
    }

    mLastMouseX = mousePosX;
    mLastMouseY = mousePosY;
    mIsMovingBody = true;
}