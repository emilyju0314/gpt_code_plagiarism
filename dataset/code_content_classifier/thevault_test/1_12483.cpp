uint32 BlendTreeParameterNode::GetParameterIndex(size_t portNr) const
    {
        // check if the parameter mask is empty
        if (m_parameterIndices.empty())
        {
            return static_cast<uint32>(portNr);
        }

        // get the mapped parameter index in case the given port is valid
        if (portNr < m_parameterIndices.size())
        {
            return m_parameterIndices[portNr];
        }

        // return failure, the input port is not in range
        return MCORE_INVALIDINDEX32;
    }