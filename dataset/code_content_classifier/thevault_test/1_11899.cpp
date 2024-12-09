void Actor::RemoveAllMaterials()
    {
        // for all LODs
        for (AZStd::vector<Material*>& materials : m_materials)
        {
            // delete all materials
            for (Material* material : materials)
            {
                material->Destroy();
            }
        }

        m_materials.clear();
    }