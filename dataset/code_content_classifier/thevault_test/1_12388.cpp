void Importer::ValidateActorSettings(ActorSettings* settings)
    {
        // After atom: Make sure we are not loading the tangents and bitangents
        if (AZStd::find(begin(settings->m_layerIDsToIgnore), end(settings->m_layerIDsToIgnore), Mesh::ATTRIB_TANGENTS) == end(settings->m_layerIDsToIgnore))
        {
            settings->m_layerIDsToIgnore.emplace_back(Mesh::ATTRIB_TANGENTS);
        }

        if (AZStd::find(begin(settings->m_layerIDsToIgnore), end(settings->m_layerIDsToIgnore), Mesh::ATTRIB_BITANGENTS) == end(settings->m_layerIDsToIgnore))
        {
            settings->m_layerIDsToIgnore.emplace_back(Mesh::ATTRIB_BITANGENTS);
        }

        // make sure we load at least the position and normals and org vertex numbers
        if(const auto it = AZStd::find(begin(settings->m_layerIDsToIgnore), end(settings->m_layerIDsToIgnore), Mesh::ATTRIB_ORGVTXNUMBERS); it != end(settings->m_layerIDsToIgnore))
        {
            settings->m_layerIDsToIgnore.erase(it);
        }
        if(const auto it = AZStd::find(begin(settings->m_layerIDsToIgnore), end(settings->m_layerIDsToIgnore), Mesh::ATTRIB_NORMALS); it != end(settings->m_layerIDsToIgnore))
        {
            settings->m_layerIDsToIgnore.erase(it);
        }
        if(const auto it = AZStd::find(begin(settings->m_layerIDsToIgnore), end(settings->m_layerIDsToIgnore), Mesh::ATTRIB_POSITIONS); it != end(settings->m_layerIDsToIgnore))
        {
            settings->m_layerIDsToIgnore.erase(it);
        }
    }