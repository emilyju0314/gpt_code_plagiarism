void ConfigBuilderBase::WritePalMetadata()
{
    // Set whole-pipeline values.
    SetUserDataLimit();
    SetSpillThreshold();
    SetPipelineHash();

    if (GeneratingMsgPack())
    {
        // Generating MsgPack metadata.
        // Set the pipeline hashes.
        auto pipelineHashNode = m_pipelineNode[Util::Abi::PipelineMetadataKey::InternalPipelineHash].getArray(true);
        pipelineHashNode[0] = m_document->getNode(m_pContext->GetPiplineHashCode());
        pipelineHashNode[1] = m_document->getNode(m_pContext->GetCacheHashCode());

        // Add the register values to the MsgPack document.
        msgpack::MapDocNode registers = m_pipelineNode[".registers"].getMap(true);
        size_t sizeInDword = m_configSize / sizeof(uint32_t);
        // Configs are composed of DWORD key/value pair, the size should be even
        LLPC_ASSERT((sizeInDword % 2) == 0);
        for (size_t i = 0; i < sizeInDword; i += 2)
        {
            auto key   = m_document->getNode((reinterpret_cast<uint32_t*>(m_pConfig))[i]);
            auto value = m_document->getNode((reinterpret_cast<uint32_t*>(m_pConfig))[i + 1]);
            // Don't export invalid metadata key and value
            if (key.getUInt() == InvalidMetadataKey)
            {
                LLPC_ASSERT(value.getUInt() == InvalidMetadataValue);
            }
            else
            {
                registers[key] = value;
            }
        }

        // Add the metadata version number.
        auto versionNode = m_document->getRoot().getMap(true)[Util::Abi::PalCodeObjectMetadataKey::Version]
                                .getArray(true);
        versionNode[0] = m_document->getNode(Util::Abi::PipelineMetadataMajorVersion);
        versionNode[1] = m_document->getNode(Util::Abi::PipelineMetadataMinorVersion);

        // Write the MsgPack document into an IR metadata node.
        std::string blob;
        m_document->writeToBlob(blob);
        auto pAbiMetaString = MDString::get(m_pModule->getContext(), blob);
        auto pAbiMetaNode = MDNode::get(m_pModule->getContext(), pAbiMetaString);
        auto pNamedMeta = m_pModule->getOrInsertNamedMetadata("amdgpu.pal.metadata.msgpack");
        pNamedMeta->addOperand(pAbiMetaNode);
    }
    else
    {
        // Generating legacy format metadata.
        // Set the pipeline hash.
        auto hash64 = m_pContext->GetPiplineHashCode();
        SetPseudoRegister(mmPIPELINE_HASH_LO, uint32_t(hash64));
        SetPseudoRegister(mmPIPELINE_HASH_HI, uint32_t(hash64 >> 32));

        // Write the metadata into an IR metadata node.
        std::vector<Metadata*> abiMeta;
        size_t sizeInDword = m_configSize / sizeof(uint32_t);
        // Configs are composed of DWORD key/value pair, the size should be even
        LLPC_ASSERT((sizeInDword % 2) == 0);
        for (size_t i = 0; i < sizeInDword; i += 2)
        {
            uint32_t key   = (reinterpret_cast<uint32_t*>(m_pConfig))[i];
            uint32_t value = (reinterpret_cast<uint32_t*>(m_pConfig))[i + 1];
            // Don't export invalid metadata key and value
            if (key == InvalidMetadataKey)
            {
                LLPC_ASSERT(value == InvalidMetadataValue);
            }
            else
            {
                abiMeta.push_back(ConstantAsMetadata::get(ConstantInt::get(m_pContext->Int32Ty(), key, false)));
                abiMeta.push_back(ConstantAsMetadata::get(ConstantInt::get(m_pContext->Int32Ty(), value, false)));
            }
        }

        for (uint32_t value : m_pseudoRegisters)
        {
            abiMeta.push_back(ConstantAsMetadata::get(ConstantInt::get(m_pContext->Int32Ty(), value, false)));
        }

        auto pAbiMetaTuple = MDTuple::get(*m_pContext, abiMeta);
        auto pAbiMetaNode = m_pModule->getOrInsertNamedMetadata("amdgpu.pal.metadata");
        pAbiMetaNode->addOperand(pAbiMetaTuple);
    }
}