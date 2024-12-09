bool MeshObject::CreateScreenSpaceMesh(Vulkan* pVulkan, glm::vec4 PosLLRadius, glm::vec4 UVLLRadius, uint32_t binding, MeshObject* meshObject)
{
    // Each quad is just a list of 6 verts (two triangles) with 4 floats per vert ...
    // ... and a 4 float color for each vert
    float Verts[6][4];
    // float Color[6][4];   <= If we want different color per vert

    // This is the same for everyone
    float VertColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

    // Note have to invert the Y-Values for Vulkan

    // [0,1,2]
    Verts[0][0] = PosLLRadius[0];
    Verts[0][1] = PosLLRadius[1];
    Verts[0][2] = UVLLRadius[0];
    Verts[0][3] = 1.0f - UVLLRadius[1];

    Verts[1][0] = PosLLRadius[0] + PosLLRadius[2];
    Verts[1][1] = PosLLRadius[1];
    Verts[1][2] = UVLLRadius[0] + UVLLRadius[2];
    Verts[1][3] = 1.0f - UVLLRadius[1];

    Verts[2][0] = PosLLRadius[0];
    Verts[2][1] = PosLLRadius[1] + PosLLRadius[3];
    Verts[2][2] = UVLLRadius[0];
    Verts[2][3] = 1.0f - (UVLLRadius[1] + UVLLRadius[3]);


    // [1, 3, 2]
    Verts[3][0] = PosLLRadius[0] + PosLLRadius[2];
    Verts[3][1] = PosLLRadius[1];
    Verts[3][2] = UVLLRadius[0] + UVLLRadius[2];
    Verts[3][3] = 1.0f - UVLLRadius[1];

    Verts[4][0] = PosLLRadius[0] + PosLLRadius[2];
    Verts[4][1] = PosLLRadius[1] + PosLLRadius[3];
    Verts[4][2] = UVLLRadius[0] + UVLLRadius[2];
    Verts[4][3] = 1.0f - (UVLLRadius[1] + UVLLRadius[3]);

    Verts[5][0] = PosLLRadius[0];
    Verts[5][1] = PosLLRadius[1] + PosLLRadius[3];
    Verts[5][2] = UVLLRadius[0];
    Verts[5][3] = 1.0f - (UVLLRadius[1] + UVLLRadius[3]);

    // Each quad is just a list of 6 verts (two triangles) with 4 floats per vert
    std::vector<vertex_layout> objVertices;
    for (uint32_t WhichVert = 0; WhichVert < 6; WhichVert++)
    {
        vertex_layout vertex;
        memset(&vertex, 0, sizeof(vertex));

        // Position data is the first part of the quad
        vertex.pos[0] = Verts[WhichVert][0];
        vertex.pos[1] = Verts[WhichVert][1];
        vertex.pos[2] = 0.0f;

        // UV data is the second part of the quad
        vertex.uv[0] = Verts[WhichVert][2];
        vertex.uv[1] = Verts[WhichVert][3];

        vertex.normal[0] = 0.0f;
        vertex.normal[1] = 0.0f;
        vertex.normal[2] = 1.0f;

        // Don't really have tangents
        vertex.tangent[0] = 0.0f;
        vertex.tangent[1] = 0.0f;
        vertex.tangent[2] = 0.0f;

        // Default vertice color is white (debug with pink if needed)
        vertex.color[0] = VertColor[0];
        vertex.color[1] = VertColor[1];
        vertex.color[2] = VertColor[2];
        vertex.color[3] = VertColor[3];

        objVertices.push_back(vertex);
    }

    meshObject->m_NumVertices = (uint32_t)objVertices.size();
    meshObject->m_VertexBuffers.resize(1);
    meshObject->m_VertexBuffers[0].Initialize(&pVulkan->GetMemoryManager(),
        objVertices.size(),
        &objVertices[0]);

    meshObject->m_VertexBuffers[0].AddBindingAndAtributes(binding, vertex_layout::sFormat);

    return true;
}