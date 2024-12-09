bool
    Window::pollEvents() const
    {
        glfwPollEvents();
        if (m_quitRequested)
        {
            m_quitRequested = false;
            return false;
        }
        return !glfwWindowShouldClose(m_pWindow);
    }