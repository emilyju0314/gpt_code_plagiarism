size_t
    computeVertexDimension(std::vector<Attribute> const& rAttributes, size_t vertexNumber)
    {
        size_t result = 0;
        for (auto const& rAttribute : rAttributes)
        {
            if (rAttribute.m_data.size() % rAttribute.m_dimension != 0)
                throw std::exception(String("Graphics error: Mismatch between data and dimension for vertex attribute '%'")
                                     .arg(rAttribute.m_name).c_str());

            if (rAttribute.m_data.size() / rAttribute.m_dimension != vertexNumber)
                throw std::exception(String("Graphics error: Mismatch between vertex attributes. Attribute '%' differs in number of vertices (has %, should have %)")
                                     .arg(rAttribute.m_name)
                                     .arg(rAttribute.m_data.size() / rAttribute.m_dimension)
                                     .arg(vertexNumber).c_str());

            result += rAttribute.m_dimension;
        }
        return result;
    }