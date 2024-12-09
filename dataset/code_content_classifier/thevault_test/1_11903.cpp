void Actor::SetNumLODLevels(size_t numLODs, bool adjustMorphSetup)
    {
        m_meshLodData.m_lodLevels.resize(numLODs);

        // reserve space for the materials
        m_materials.resize(numLODs);

        if (adjustMorphSetup)
        {
            m_morphSetups.resize(numLODs);
            AZStd::fill(begin(m_morphSetups), AZStd::next(begin(m_morphSetups), numLODs), nullptr);
        }
    }