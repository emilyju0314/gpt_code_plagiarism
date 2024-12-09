void Actor::RemoveMaterial(size_t lodLevel, size_t index)
    {
        MCORE_ASSERT(lodLevel < m_materials.size());

        // first of all remove the given material
        m_materials[lodLevel][index]->Destroy();
        m_materials[lodLevel].erase(AZStd::next(begin(m_materials[lodLevel]), index));
    }