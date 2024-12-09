void GLActor::Cleanup()
    {
        // get rid of all index and vertex buffers
        for (AZStd::vector<VertexBuffer*>& vertexBuffers : m_vertexBuffers)
        {
            for (VertexBuffer* vertexBuffer : vertexBuffers)
            {
                delete vertexBuffer;
            }
        }
        for (AZStd::vector<IndexBuffer*>& indexBuffers : m_indexBuffers)
        {
            for (IndexBuffer* indexBuffer : indexBuffers)
            {
                delete indexBuffer;
            }
        }

        // delete all materials
        for (AZStd::vector<MaterialPrimitives*>& materialsPerLod : m_materials)
        {
            for (MaterialPrimitives* materialPrimitives : materialsPerLod)
            {
                delete materialPrimitives->m_material;
                delete materialPrimitives;
            }
        }
    }