bool SceneDemo::mouseButtonEvent(int button, bool down, int mods, double mousePosX, double mousePosY) {

    // Left mouse click with CTRL key pressed on keyboard (moving a body)
    if (down && (mods & GLFW_MOD_CONTROL)) {

        moveBodyWithMouse(mousePosX, mousePosY);
        return true;
    }

    mIsMovingBody = false;
    mMovingBody = nullptr;

    return Scene::mouseButtonEvent(button, down, mods, mousePosX, mousePosY);
}