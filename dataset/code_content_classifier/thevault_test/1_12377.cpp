void HairDispatchItem::InitSkinningDispatch(
                RPI::Shader* shader,
                RPI::ShaderResourceGroup* hairGenerationSrg,
                RPI::ShaderResourceGroup* hairSimSrg,
                uint32_t elementsAmount )
            {
                m_shader = shader;
                RHI::DispatchDirect dispatchArgs(
                    elementsAmount, 1, 1,
                    TRESSFX_SIM_THREAD_GROUP_SIZE, 1, 1
                );
                m_dispatchItem.m_arguments = dispatchArgs;
                RHI::PipelineStateDescriptorForDispatch pipelineDesc;
                m_shader->GetVariant(RPI::ShaderAsset::RootShaderVariantStableId).ConfigurePipelineState(pipelineDesc);
                m_dispatchItem.m_pipelineState = m_shader->AcquirePipelineState(pipelineDesc);
                m_dispatchItem.m_shaderResourceGroupCount = 2;      // the per pass will be added by each pass.
                m_dispatchItem.m_shaderResourceGroups = {
                    hairGenerationSrg->GetRHIShaderResourceGroup(), // Static generation data
                    hairSimSrg->GetRHIShaderResourceGroup()         // Dynamic data changed between passes
                };
            }