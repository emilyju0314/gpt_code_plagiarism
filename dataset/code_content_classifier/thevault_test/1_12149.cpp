void HairPPLLRasterPass::BuildInternal()
            {
                RasterPass::BuildInternal();    // change this to call parent if the method exists

                if (!AcquireFeatureProcessor())
                {
                    return;
                }

                if (!LoadShaderAndPipelineState())
                {
                    return;
                }

                // Output
                AttachBufferToSlot(Name{ "PerPixelLinkedList" }, m_featureProcessor->GetPerPixelListBuffer());
            }