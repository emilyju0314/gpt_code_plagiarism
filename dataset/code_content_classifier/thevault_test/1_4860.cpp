bool Scene::mouseButtonEvent(int /*button*/, bool down, int /*mods*/, double mousePosX, double mousePosY) {

    // If the mouse button is pressed
    if (down) {
        mLastMouseX = mousePosX;
        mLastMouseY = mousePosY;
    }

    return true;
}