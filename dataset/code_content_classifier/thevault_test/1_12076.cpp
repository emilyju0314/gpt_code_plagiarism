Data::Instance<RPI::Buffer> UtilityClass::CreateBuffer(
                [[maybe_unused]] const char* warningHeader,
                SrgBufferDescriptor& bufferDesc,
                Data::Instance<RPI::ShaderResourceGroup> srg)
            {
                // If srg is provided, match the shader Srg bind index (returned via the descriptor)
                if (srg)
                {   // Not always do we want to associate Srg when creating a buffer
                    bufferDesc.m_resourceShaderIndex = srg->FindShaderInputBufferIndex(bufferDesc.m_paramNameInSrg).GetIndex();
                    if (bufferDesc.m_resourceShaderIndex == uint32_t(-1))
                    {
                        AZ_Error(warningHeader, false, "Failed to find shader input index for [%s] in the SRG.",
                            bufferDesc.m_paramNameInSrg.GetCStr());
                        return nullptr;
                    }
                }

                // Descriptor setting
                RPI::CommonBufferDescriptor desc;
                desc.m_elementFormat = bufferDesc.m_elementFormat;
                desc.m_poolType = bufferDesc.m_poolType;;
                desc.m_elementSize = bufferDesc.m_elementSize;
                desc.m_bufferName = bufferDesc.m_bufferName.GetCStr();
                desc.m_byteCount = (uint64_t)bufferDesc.m_elementCount * bufferDesc.m_elementSize;
                desc.m_bufferData = nullptr;    // set during asset load - use Update

                // Buffer creation
                return RPI::BufferSystemInterface::Get()->CreateBufferFromCommonPool(desc);
            }