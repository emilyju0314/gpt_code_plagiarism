TEST_F(InstanceDataHierarchyGroupTestFixture, ValidatingGroupAndSubGroupHierarchy)
    {
        using AzToolsFramework::InstanceDataHierarchy;
        using AzToolsFramework::InstanceDataNode;

        for (auto child : componentNode1->GetChildren())
        {
            AZStd::string childName(child.GetElementMetadata()->m_name);
            if (childName.compare("GroupFloat") == 0)
            {
                EXPECT_STREQ(child.GetGroupElementMetadata()->m_description, "Normal Group");
            }
            if (childName.compare("ToggleGroupInt") == 0)
            {
                EXPECT_STREQ(child.GetGroupElementMetadata()->m_description, "Group Toggle");
            }
            if ((childName.compare("SubDataNormal") == 0) || (childName.compare("SubDataToggle") == 0))
            {
                for (auto subChild : child.GetChildren())
                {
                    childName = subChild.GetElementMetadata()->m_name;
                    if (childName.compare("SubInt") == 0)
                    {
                        EXPECT_STREQ(subChild.GetGroupElementMetadata()->m_description, "Normal SubGroup");
                    }
                    if (childName.compare("SubFloat") == 0)
                    {
                        EXPECT_STREQ(subChild.GetGroupElementMetadata()->m_description, "SubGroup Toggle");
                    }
                }
            }
        }
    }