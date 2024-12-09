TEST_F(InstanceDataHierarchyGroupTestFixture, GroupToggleIsClassElementGroup)
    {
        using AzToolsFramework::InstanceDataHierarchy;
        using AzToolsFramework::InstanceDataNode;

        for (auto child : componentNode1->GetChildren())
        {
            AZStd::string childName(child.GetElementMetadata()->m_name);
            if (childName.compare("GroupToggle") == 0)
            {
                EXPECT_EQ(child.GetElementEditMetadata()->m_elementId, AZ::Edit::ClassElements::Group);
            }
            if ((childName.compare("SubDataNormal") == 0) || (childName.compare("SubDataToggle") == 0))
            {
                for (auto subChild : child.GetChildren())
                {
                    childName = subChild.GetElementMetadata()->m_name;
                    if (childName.compare("SubToggle") == 0)
                    {
                        EXPECT_EQ(subChild.GetElementEditMetadata()->m_elementId, AZ::Edit::ClassElements::Group);
                    }
                    else
                    {
                        EXPECT_NE(subChild.GetElementEditMetadata()->m_elementId, AZ::Edit::ClassElements::Group);
                    }
                }
            }
        }
    }