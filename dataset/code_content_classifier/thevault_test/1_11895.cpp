bool ShaderInputNameIndex::ValidateOrFindBufferIndex(const ShaderResourceGroupLayout* srgLayout)
        {
            if (IsValid())      // 99% use case, check this first for a quick early out
            {
                return true;
            }
            if (!m_initialized)
            {
                FindBufferIndex(srgLayout);
                return IsValid();
            }
            return false;
        }