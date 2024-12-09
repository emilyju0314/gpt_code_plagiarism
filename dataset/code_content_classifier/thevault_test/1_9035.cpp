bool MeshObject::LoadObj(Vulkan* pVulkan, AssetManager& assetManager, const std::string& filename, uint32_t binding, MeshObject* meshObject)
{
    // Destroy object before re-creating
    meshObject->Destroy();

    tinyobj::attrib_t                   attrib;
    std::vector<tinyobj::shape_t>       shapes;
    std::vector<tinyobj::material_t>    materials;

    std::string warn;
    std::string err;

    // Load the obj file in to memory.
    AssetMemStream<char> objFile;
    if (!assetManager.LoadFileIntoMemory(filename, objFile))
    {
        LOGE("tinyobj failed to open: %s", filename.c_str());
        return false;
    }

    // Create a stream from the loaded string data.
    MaterialFileReader matFileReader(assetManager, filename);

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, &objFile, &matFileReader);
    objFile.clear();

    if (!err.empty())
    {
        LOGE("tinyobj error (%s) loading %s", err.c_str(), filename.c_str());
        return false;
    }

    if (!ret)
    {
        LOGE("tinyobj failed to load %s", filename.c_str());
        return false;
    }

    std::vector<vertex_layout> objVertices;
    LOGI("Mesh object %s has %d Shape[s]", filename.c_str(), (int)shapes.size());
    if (shapes.size() > 1)
    {
        LOGE("    Mesh loader only supports one shape per file!");
        return false;
    }

    // Loop over shapes
    for (size_t WhichShape = 0; WhichShape < shapes.size(); WhichShape++)
    {
        uint32_t NumIndices = (uint32_t)shapes[WhichShape].mesh.indices.size();

        LOGI("    Shape %d:", (int)WhichShape);
        LOGI("      %d Indices (%d triangles)", NumIndices, NumIndices / 3);
        LOGI("      %d Positions", (int)attrib.vertices.size() / 3);
        LOGI("      %d Normals", (int)attrib.normals.size() / 3);
        LOGI("      %d UVs", (int)attrib.texcoords.size() / 2);

        // Loop over faces(polygon)
        size_t index_offset = 0;
        for (size_t WhichFace = 0; WhichFace < shapes[WhichShape].mesh.num_face_vertices.size(); WhichFace++)
        {

            int VertsPerFace = shapes[WhichShape].mesh.num_face_vertices[WhichFace];

            // Loop over vertices in the face.
            for (size_t WhichVert = 0; WhichVert < VertsPerFace; WhichVert++)
            {
                // access to vertex
                tinyobj::index_t idx = shapes[WhichShape].mesh.indices[index_offset + WhichVert];
                tinyobj::real_t vx = attrib.vertices[3 * idx.vertex_index + 0];
                tinyobj::real_t vy = attrib.vertices[3 * idx.vertex_index + 1];
                tinyobj::real_t vz = attrib.vertices[3 * idx.vertex_index + 2];
                tinyobj::real_t nx = attrib.normals[3 * idx.normal_index + 0];
                tinyobj::real_t ny = attrib.normals[3 * idx.normal_index + 1];
                tinyobj::real_t nz = attrib.normals[3 * idx.normal_index + 2];
                tinyobj::real_t tx = attrib.texcoords[2 * idx.texcoord_index + 0];
                tinyobj::real_t ty = attrib.texcoords[2 * idx.texcoord_index + 1];
                // Optional: vertex colors
                // tinyobj::real_t red = attrib.colors[3*idx.vertex_index+0];
                // tinyobj::real_t green = attrib.colors[3*idx.vertex_index+1];
                // tinyobj::real_t blue = attrib.colors[3*idx.vertex_index+2];

                vertex_layout vertex;
                vertex.pos[0] = vx;
                vertex.pos[1] = vy;
                vertex.pos[2] = vz;

                vertex.normal[0] = nx;
                vertex.normal[1] = ny;
                vertex.normal[2] = nz;

                vertex.uv[0] = tx;
                vertex.uv[1] = ty;

                // Default vertice color is white (debug with pink if needed)
                vertex.color[0] = 1.0f;
                vertex.color[1] = 1.0f;
                vertex.color[2] = 1.0f;
                vertex.color[3] = 1.0f;

                // No tangents in OBJ files :(
                vertex.tangent[0] = 0.0f;
                vertex.tangent[1] = 1.0f;
                vertex.tangent[2] = 0.0f;

                objVertices.push_back(vertex);
            }   // WhichVert
            index_offset += VertsPerFace;

            // per-face material
            // shapes[WhichShape].mesh.material_ids[WhichFace];
        }   // WhichFace

    }   // WhichShape

    meshObject->m_NumVertices = (uint32_t)objVertices.size();
    meshObject->m_VertexBuffers.resize(1);
    meshObject->m_VertexBuffers[0].Initialize(&pVulkan->GetMemoryManager(),
                                          objVertices.size(),
                                          &objVertices[0]);

    meshObject->m_VertexBuffers[0].AddBindingAndAtributes(binding, vertex_layout::sFormat);

    return true;
}