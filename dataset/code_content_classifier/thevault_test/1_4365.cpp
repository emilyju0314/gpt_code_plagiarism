void InputCallbacks::I_MouseButtonForwarder(GLFWwindow* window, int button, int action, int mods)
{
    PlanetariumApp* app = reinterpret_cast<PlanetariumApp*>(glfwGetWindowUserPointer(window));
    if (app) {

        app->I_MouseButton(window, button, action, mods);
    }
}