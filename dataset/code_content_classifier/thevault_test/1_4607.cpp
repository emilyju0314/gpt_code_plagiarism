void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    cameraRadius -= yoffset/2;
    if (basePitch > 20.0f)
        basePitch = 20.0f;
    if (basePitch < 0.0f)
        basePitch = 0.0f;
}