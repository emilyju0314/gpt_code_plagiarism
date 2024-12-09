bool SceneDemo::mouseMotionEvent(double xMouse, double yMouse, int leftButtonState, int rightButtonState, int middleButtonState, int altKeyState) {

    if (mIsMovingBody) {
        moveBodyWithMouse(xMouse, yMouse);
        return true;
    }

    return Scene::mouseMotionEvent(xMouse, yMouse, leftButtonState, rightButtonState, middleButtonState, altKeyState);
}