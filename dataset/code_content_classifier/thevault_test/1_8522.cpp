void StaticMesh::BufferData(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
    {
        //Generate the VAO
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        //Generate the vertices VBO
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

        //Generate the indices EAB
        glGenBuffers(1, &eab);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eab);
        size = indices.size();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * size, &indices[0], GL_STATIC_DRAW);

        //Assign the attributes
        glEnableVertexAttribArray((int)ProgramAttribute::Position);
        glVertexAttribPointer((int)ProgramAttribute::Position,
            3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, position));

        glEnableVertexAttribArray((int)ProgramAttribute::Normal);
        glVertexAttribPointer((int)ProgramAttribute::Normal,
            3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, normal));

        glEnableVertexAttribArray((int)ProgramAttribute::Tangent);
        glVertexAttribPointer((int)ProgramAttribute::Tangent,
            4, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, tangent));

        glEnableVertexAttribArray((int)ProgramAttribute::UV);
        glVertexAttribPointer((int)ProgramAttribute::UV,
            2, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, uv));
    }