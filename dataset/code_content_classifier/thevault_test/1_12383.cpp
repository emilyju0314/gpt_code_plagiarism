NodeMap* Importer::LoadNodeMap(MCore::File* f, NodeMapSettings* settings)
    {
        MCORE_ASSERT(f);
        MCORE_ASSERT(f->GetIsOpen());

        // execute the pre-passes
        if (f->GetType() != MCore::MemoryFile::TYPE_ID)
        {
            MCore::LogError("Given file is not a memory file. Cannot process pre-passes.");
            return nullptr;
        }

        // copy over the settings, or use defaults
        NodeMapSettings nodeMapSettings;
        if (settings)
        {
            nodeMapSettings = *settings;
        }

        // create the shared data
        AZStd::vector<SharedData*> sharedData;
        PrepareSharedData(sharedData);

        //-----------------------------------------------

        // load the file header
        FileFormat::NodeMap_Header fileHeader;
        f->Read(&fileHeader, sizeof(FileFormat::NodeMap_Header));
        if (fileHeader.m_fourCc[0] != 'N' || fileHeader.m_fourCc[1] != 'O' || fileHeader.m_fourCc[2] != 'M' || fileHeader.m_fourCc[3] != 'P')
        {
            MCore::LogError("The node map file is not a valid node map file.");
            f->Close();
            return nullptr;
        }

        // get the endian type
        MCore::Endian::EEndianType endianType = (MCore::Endian::EEndianType)fileHeader.m_endianType;

        // create the node map
        NodeMap* nodeMap = NodeMap::Create();

        // init the import parameters
        ImportParameters params;
        params.m_sharedData          = &sharedData;
        params.m_endianType          = endianType;
        params.m_nodeMap             = nodeMap;
        params.m_nodeMapSettings     = &nodeMapSettings;

        // process all chunks
        while (ProcessChunk(f, params))
        {
        }

        // close the file and return a pointer to the actor we loaded
        f->Close();

        // get rid of shared data
        ResetSharedData(sharedData);
        sharedData.clear();

        // return the created actor
        return nodeMap;
    }