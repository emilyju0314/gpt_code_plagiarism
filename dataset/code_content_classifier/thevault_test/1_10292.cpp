Component::RenderData
    create(Shader const& rShader,
           std::vector<Attribute> const& rAttributes,
           std::vector<int> const& rIndices)
    {
        Component::RenderData result;
        result.m_shaderProgramId = rShader.m_programId;
        result.m_vertexVisits = static_cast<int>(rIndices.size());

        if (rAttributes.empty())
            return result;

        size_t const vertexNumber = rAttributes.at(0).m_data.size() / rAttributes.at(0).m_dimension;
        auto const vertexDimension = computeVertexDimension(rAttributes, vertexNumber);
        auto const accumulatedAttributes = accumulateAttributes(rAttributes, vertexNumber, vertexDimension);

        // Find attribute locations
        std::vector<AttributeInfo> attributeInfos;
        for (auto const& rAttribute : rAttributes)
        {
            auto const location = glGetAttribLocation(result.m_shaderProgramId, rAttribute.m_name.c_str());
            if (location < 0)
                throw std::exception(String("Graphics error: Failed to retrieve %'s location.")
                                     .arg(rAttribute.m_name).c_str());
            attributeInfos.push_back(AttributeInfo{location, rAttribute.m_dimension});
        }

        // Create vertex array and its buffers
        unsigned int vertexBufferObject = 0;
        unsigned int indexBufferObject = 0;
        glGenVertexArrays(1, &result.m_vertexArrayObject);
        glGenBuffers(1, &vertexBufferObject);
        glGenBuffers(1, &indexBufferObject);

        glBindVertexArray(result.m_vertexArrayObject);

        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
        glBufferData(GL_ARRAY_BUFFER, accumulatedAttributes.size() * sizeof(float), accumulatedAttributes.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, rIndices.size() * sizeof(int), rIndices.data(), GL_STATIC_DRAW);

        // Pass attribute meta data to OpenGL
        auto const vertexSize = static_cast<int>(vertexDimension * sizeof(float));
        size_t offset = 0;
        for (auto const& rAttributeInfo : attributeInfos)
        {
            glVertexAttribPointer(rAttributeInfo.m_location, static_cast<int>(rAttributeInfo.m_dimension), GL_FLOAT, GL_FALSE, vertexSize, (void*)offset);
            glEnableVertexAttribArray(rAttributeInfo.m_location);
            offset += rAttributeInfo.m_dimension * sizeof(float);
        }

        return result;
    }