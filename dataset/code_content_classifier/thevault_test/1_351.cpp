Scene::Scene() {
    //set clear color to black.
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);

    //create geometry.
    bounds = new SimulationBoundaries(-1, 1, -1, 1, 0, 1.5f);
    waterSurface = new WaterSurface(2, 2, 0, 0, 0.5f);
    objects.push_back(new BeachBall(0.1f, 0.25f, 0, 0, 1));

    //create camera.
    vec3 cameraPosition = vec3(0, -3, 1.5f);
    vec3 cameraTarget = vec3(0, 0, 0.5f);//center of water surface.
    vec3 upVector = vec3(0, 1, 0);
    viewMatrix = lookAt(cameraPosition, cameraTarget, upVector);

    int error = glGetError();
    if (error != 0) {
        fprintf(stderr, "Error during initialization\n");
        glfwTerminate();
        exit(-1);
    }
}