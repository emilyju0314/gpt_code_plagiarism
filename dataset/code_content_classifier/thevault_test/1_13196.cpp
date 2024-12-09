void
Volume::createVolume()
{
    glm::vec3 min, max;
    min = -(glm::vec3(_dims) * (_resolution * 0.5f));
    max =  (glm::vec3(_dims) * (_resolution * 0.5f));

    static GLfloat vertices[] = {
        // vertices            texcoords
        max.x, max.y, max.z,   1.0f, 1.0f, 1.0f,
        min.x, max.y, max.z,   0.0f, 1.0f, 1.0f,
        max.x, max.y, min.z,   1.0f, 1.0f, 0.0f,
        min.x, max.y, min.z,   0.0f, 1.0f, 0.0f,
        max.x, min.y, max.z,   1.0f, 0.0f, 1.0f,
        min.x, min.y, max.z,   0.0f, 0.0f, 1.0f,
        min.x, min.y, min.z,   0.0f, 0.0f, 0.0f,
        max.x, min.y, min.z,   1.0f, 0.0f, 0.0f
    };
    static GLuint indices[] = {
        3, 2, 6, 7, 4, 2, 0,
        3, 1, 6, 5, 4, 1, 0
    };

    unsigned int vbo, ebo;
    glGenVertexArrays(1, &_box_vao);
    glBindVertexArray(_box_vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(vertices),
                 vertices,
                 GL_STATIC_DRAW);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 sizeof(indices),
                 indices,
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                          6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
                          6 * sizeof(float), (void*)(3 * sizeof(float)));
}