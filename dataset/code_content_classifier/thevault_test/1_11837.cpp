void ValidateCommonDescriptorFields(const MaterialTypeSourceData::PropertyDefinition& expectedValues, const MaterialPropertyDescriptor* propertyDescriptor)
        {
            EXPECT_EQ(propertyDescriptor->GetDataType(), expectedValues.m_dataType);
            EXPECT_EQ(propertyDescriptor->GetOutputConnections().size(), expectedValues.m_outputConnections.size());
            for (int i = 0; i < expectedValues.m_outputConnections.size() && i < propertyDescriptor->GetOutputConnections().size(); ++i)
            {
                EXPECT_EQ(propertyDescriptor->GetOutputConnections()[i].m_type, expectedValues.m_outputConnections[i].m_type);
                EXPECT_EQ(propertyDescriptor->GetOutputConnections()[i].m_containerIndex.GetIndex(), expectedValues.m_outputConnections[i].m_shaderIndex);
            }
        }