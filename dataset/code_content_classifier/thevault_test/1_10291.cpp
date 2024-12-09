std::vector<float>
    accumulateAttributes(std::vector<Attribute> const& rAttributes, size_t vertexNumber, size_t vertexDimension)
    {
        std::vector<float> result(vertexNumber * vertexDimension, 0.0f);
        size_t offset = 0;
        for (auto const& rAttribute : rAttributes)
        {
            for (size_t vertex = 0; vertex < vertexNumber; ++vertex)
            {
                auto const accumulatedIndex = vertex * vertexDimension + offset;
                auto const attributeIndex = vertex * rAttribute.m_dimension;

                for (size_t component = 0; component < rAttribute.m_dimension; ++component)
                    result.at(accumulatedIndex + component) = rAttribute.m_data.at(attributeIndex + component);
            }
            offset += rAttribute.m_dimension;
        }
        return result;
    }