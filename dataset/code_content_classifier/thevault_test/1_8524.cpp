void ConvertObjToMesh(
        //In
        std::vector<Vector3>& positions,
        std::vector<Vector3>& normals,
        std::vector<Vector2>& uvs,
        std::vector<std::array<std::array<int, 3>, 3>>& faces,
        //Out
        std::vector<Vertex>& vertices,
        std::vector<GLuint>& indices)
    {
        //This maps vertices to their indices
        std::unordered_map<std::array<int, 3>, int, VertexIndicesHash, VertexIndicesEqual> vertexToIndex;

        for (auto& face : faces)
        {
            //Create the vertices from the face
            for (int i = 0; i < 3; i++)
            {
                auto vertexIndices = face[i];

                int index;
                auto iter = vertexToIndex.find(vertexIndices);
                if (iter == vertexToIndex.end())
                {
                    Vertex vertex;
                    vertex.position = positions[vertexIndices[0]];
                    if (vertexIndices[1] != -1)
                    {
                        vertex.uv = uvs[vertexIndices[1]];
                    }
                    if (vertexIndices[2] != -1)
                    {
                        vertex.normal = normals[vertexIndices[2]];
                    }

                    //It hasn't already been added to the list
                    vertices.push_back(vertex);
                    index = vertices.size() - 1;

                    //Add to the hashmap for later
                    vertexToIndex.insert(
                        std::pair<std::array<int, 3>, int>(vertexIndices, index));
                }
                else
                {
                    //It already exists, use the existing index
                    index = iter->second;
                }

                //Add the index to the list
                indices.push_back(index);
            }
        }
    }