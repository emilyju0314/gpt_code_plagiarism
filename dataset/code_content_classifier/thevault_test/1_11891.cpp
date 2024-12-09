TEST_P(InstanceDataHierarchyGroupTestFixtureParameterized, ValidatingGroupAndSubGroupParents)
    {
        using AzToolsFramework::InstanceDataHierarchy;
        using AzToolsFramework::InstanceDataNode;

        const char* paramName = GetParam();
        for (auto child : componentNode1->GetChildren())
        {
            AZStd::string childName(child.GetElementMetadata()->m_name);
            if (childName.compare(paramName) == 0)
            {
                EXPECT_STREQ(child.GetParent()->GetClassMetadata()->m_name, "GroupTestComponent");
            }
            if ((childName.compare("SubDataNormal") == 0) || (childName.compare("SubDataToggle") == 0))
            {
                for (auto subChild : child.GetChildren())
                {
                    childName = subChild.GetElementMetadata()->m_name;
                    if (childName.compare(paramName) == 0)
                    {
                        EXPECT_STREQ(subChild.GetParent()->GetClassMetadata()->m_name, "SubData");
                    }
                }
            }
        }
    }