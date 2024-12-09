bool ShaderVariantTreeAssetCreator::End(Data::Asset<ShaderVariantTreeAsset>& result)
        {
            if (!ValidateIsReady())
            {
                return false;
            }

            if (!m_shaderOptionGroupLayout)
            {
                ReportError("No ShaderOptionGroupLayout has been set. Failed to finalize the ShaderVariantTreeAsset.");
                return false;
            }

            if (m_variantInfos.size() == 0)
            {
                ReportError("The list of source variants is not valid. Failed to finalize the ShaderVariantTreeAsset.");
                return false;
            }

            if (!EndInternal(result))
            {
                return false;
            }

            if (!m_asset->FinalizeAfterLoad())
            {
                ReportError("Failed to finalize the ShaderVariantTreeAsset.");
                return false;
            }

            m_asset->SetReady();
            return EndCommon(result);
        }