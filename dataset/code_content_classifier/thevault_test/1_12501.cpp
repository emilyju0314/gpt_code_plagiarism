size_t Node::RemoveAllAttributesByType(uint32 attributeTypeID)
    {
        return AZStd::erase_if(m_attributes, [attributeTypeID](const NodeAttribute* attribute)
        {
            return attribute->GetType() == attributeTypeID;
        });
    }