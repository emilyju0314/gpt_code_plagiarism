AZ::Vector3 CoordinateSystemConverter::ConvertScale(const AZ::Vector3& input) const
    {
        if (!m_needsConversion)
        {
            return input;
        }

        return AZ::Vector3( input.GetElement(m_targetBasisIndices[0]), 
                            input.GetElement(m_targetBasisIndices[1]), 
                            input.GetElement(m_targetBasisIndices[2]) );
    }